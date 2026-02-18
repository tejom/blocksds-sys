use std::env;
use std::path::PathBuf;
use std::process::Command;

fn main() {
    let blocksds = env::var("BLOCKSDS")
        .unwrap_or_else(|_| "/opt/wonderful/thirdparty/blocksds/core".to_string());
    let wonderful = env::var("WONDERFUL_TOOLCHAIN")
        .unwrap_or_else(|_| "/opt/wonderful".to_string());
    let gcc_prefix = format!("{wonderful}/toolchain/gcc-arm-none-eabi");
    let libnds = format!("{blocksds}/libs/libnds");
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

    // Generate Rust bindings
    let bindings = bindgen::Builder::default()
        .header(format!("{manifest_dir}/nds_wrapper.h"))
        .use_core()
        .clang_args([
            "-DARM9",
            "-target",
            "arm-none-eabi",
            "-mcpu=arm946e-s",
            "-isystem",
            &format!("{gcc_prefix}/arm-none-eabi/include"),
            &format!("-I{libnds}/include"),
        ])
        .layout_tests(false)
        .generate_comments(false)
        .derive_default(true)
        .generate()
        .expect("Unable to generate bindings");

    bindings
        .write_to_file(out_path.join("nds_bindings.rs"))
        .expect("Couldn't write bindings!");

    // Compile C wrappers for static inline functions and macros
    let gcc = format!("{gcc_prefix}/bin/arm-none-eabi-gcc");
    let obj = out_path.join("nds_wrapper.o");
    let status = Command::new(&gcc)
        .args([
            "-DARM9",
            "-mcpu=arm946e-s+nofp",
            "-mthumb",
            "-O2",
            "-ffunction-sections",
            "-fdata-sections",
            "-c",
            &format!("-I{libnds}/include"),
            &format!("-isystem{gcc_prefix}/arm-none-eabi/include"),
            "-xc",
            &format!("{manifest_dir}/nds_wrapper.h"),
            "-o",
        ])
        .arg(obj.to_str().unwrap())
        .status()
        .expect("Failed to run arm-none-eabi-gcc");
    assert!(status.success(), "Failed to compile nds_wrapper");

    let ar = format!("{gcc_prefix}/bin/arm-none-eabi-ar");
    let lib = out_path.join("libnds_wrapper.a");
    let status = Command::new(&ar)
        .args(["rcs"])
        .arg(lib.to_str().unwrap())
        .arg(obj.to_str().unwrap())
        .status()
        .expect("Failed to run arm-none-eabi-ar");
    assert!(status.success(), "Failed to create libnds_wrapper.a");

    println!("cargo:rustc-link-search=native={}", out_path.display());
    println!("cargo:rustc-link-lib=static=nds_wrapper");
    println!("cargo:rerun-if-changed={manifest_dir}/nds_wrapper.h");
}
