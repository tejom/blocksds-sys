#![no_std]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(clippy::all)]

include!(concat!(env!("OUT_DIR"), "/nds_bindings.rs"));

pub const fn rgb15(r: u16, g: u16, b: u16) -> u16 {
    r | (g << 5) | (b << 10)
}

// Pointer constants for memory-mapped addresses that C defines as macros
pub const BG_PALETTE_ADDR: *mut u16 = 0x0500_0000 as *mut u16;
pub const BG_PALETTE_SUB_ADDR: *mut u16 = 0x0500_0400 as *mut u16;
pub const SPRITE_PALETTE_ADDR: *mut u16 = 0x0500_0200 as *mut u16;
pub const SPRITE_PALETTE_SUB_ADDR: *mut u16 = 0x0500_0600 as *mut u16;

pub const BG_GFX_ADDR: *mut u16 = 0x0600_0000 as *mut u16;
pub const BG_GFX_SUB_ADDR: *mut u16 = 0x0620_0000 as *mut u16;
pub const SPRITE_GFX_ADDR: *mut u16 = 0x0640_0000 as *mut u16;
pub const SPRITE_GFX_SUB_ADDR: *mut u16 = 0x0660_0000 as *mut u16;

pub const VRAM_A_ADDR: *mut u16 = 0x0680_0000 as *mut u16;
pub const VRAM_B_ADDR: *mut u16 = 0x0682_0000 as *mut u16;
pub const VRAM_C_ADDR: *mut u16 = 0x0684_0000 as *mut u16;
pub const VRAM_D_ADDR: *mut u16 = 0x0686_0000 as *mut u16;

pub const fn char_base_block(n: usize) -> *mut u16 {
    (n * 0x4000 + 0x0600_0000) as *mut u16
}

pub const fn screen_base_block(n: usize) -> *mut u16 {
    (n * 0x800 + 0x0600_0000) as *mut u16
}
