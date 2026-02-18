#include <nds.h>
#include <stdio.h>

// Static inline function wrappers
void __wrap_videoSetMode(u32 mode) { videoSetMode(mode); }
void __wrap_videoSetModeSub(u32 mode) { videoSetModeSub(mode); }
void __wrap_vramSetBankA(VRAM_A_TYPE a) { vramSetBankA(a); }
void __wrap_vramSetBankB(VRAM_B_TYPE b) { vramSetBankB(b); }
void __wrap_vramSetBankC(VRAM_C_TYPE c) { vramSetBankC(c); }
void __wrap_vramSetBankD(VRAM_D_TYPE d) { vramSetBankD(d); }
void __wrap_vramSetBankE(VRAM_E_TYPE e) { vramSetBankE(e); }
void __wrap_vramSetBankF(VRAM_F_TYPE f) { vramSetBankF(f); }
void __wrap_vramSetBankG(VRAM_G_TYPE g) { vramSetBankG(g); }
void __wrap_vramSetBankH(VRAM_H_TYPE h) { vramSetBankH(h); }
void __wrap_vramSetBankI(VRAM_I_TYPE i) { vramSetBankI(i); }
void __wrap_lcdSwap(void) { lcdSwap(); }
void __wrap_lcdMainOnTop(void) { lcdMainOnTop(); }
void __wrap_lcdMainOnBottom(void) { lcdMainOnBottom(); }
void __wrap_videoBgEnable(int number) { videoBgEnable(number); }
void __wrap_videoBgEnableSub(int number) { videoBgEnableSub(number); }
void __wrap_videoBgDisable(int number) { videoBgDisable(number); }
void __wrap_videoBgDisableSub(int number) { videoBgDisableSub(number); }

// BG inline wrappers
int __wrap_bgInit(int layer, BgType type, BgSize size, int mapBase, int tileBase) { return bgInit(layer, type, size, mapBase, tileBase); }
int __wrap_bgInitSub(int layer, BgType type, BgSize size, int mapBase, int tileBase) { return bgInitSub(layer, type, size, mapBase, tileBase); }
u16* __wrap_bgGetGfxPtr(int id) { return bgGetGfxPtr(id); }
u16* __wrap_bgGetMapPtr(int id) { return bgGetMapPtr(id); }
void __wrap_bgSetScroll(int id, int x, int y) { bgSetScroll(id, x, y); }
void __wrap_bgUpdate(void) { bgUpdate(); }
void __wrap_bgSetPriority(int id, unsigned int priority) { bgSetPriority(id, priority); }

// DMA inline wrappers
void __wrap_dmaCopy(const void *source, void *dest, uint32_t size) { dmaCopy(source, dest, size); }
void __wrap_dmaCopyWords(uint8_t ch, const void *src, void *dest, uint32_t size) { dmaCopyWords(ch, src, dest, size); }
void __wrap_dmaCopyHalfWords(uint8_t ch, const void *src, void *dest, uint32_t size) { dmaCopyHalfWords(ch, src, dest, size); }

// GL inline wrappers
void __wrap_glEnable(int bits) { glEnable(bits); }
void __wrap_glDisable(int bits) { glDisable(bits); }
void __wrap_glBegin(GL_GLBEGIN_ENUM mode) { glBegin(mode); }
void __wrap_glEnd(void) { glEnd(); }
void __wrap_glClearDepth(fixed12d3 depth) { glClearDepth(depth); }
void __wrap_glColor3b(uint8_t red, uint8_t green, uint8_t blue) { glColor3b(red, green, blue); }
void __wrap_glColor(rgb color) { glColor(color); }
void __wrap_glVertex3v16(v16 x, v16 y, v16 z) { glVertex3v16(x, y, z); }
void __wrap_glVertex2v16(v16 x, v16 y) { glVertex2v16(x, y); }
void __wrap_glTexCoord2t16(t16 u, t16 v) { glTexCoord2t16(u, v); }
void __wrap_glPushMatrix(void) { glPushMatrix(); }
void __wrap_glPopMatrix(int num) { glPopMatrix(num); }
void __wrap_glRestoreMatrix(int index) { glRestoreMatrix(index); }
void __wrap_glStoreMatrix(int index) { glStoreMatrix(index); }
void __wrap_glTranslatef32(int x, int y, int z) { glTranslatef32(x, y, z); }
void __wrap_glScalef32(int x, int y, int z) { glScalef32(x, y, z); }
void __wrap_glLight(int id, rgb color, v10 x, v10 y, v10 z) { glLight(id, color, x, y, z); }
void __wrap_glNormal(u32 normal) { glNormal(normal); }
void __wrap_glLoadIdentity(void) { glLoadIdentity(); }
void __wrap_glMatrixMode(GL_MATRIX_MODE_ENUM mode) { glMatrixMode(mode); }
void __wrap_glViewport(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) { glViewport(x1, y1, x2, y2); }
void __wrap_glFlush(u32 mode) { glFlush(mode); }
void __wrap_glMaterialShininess(void) { glMaterialShininess(); }
void __wrap_glPolyFmt(u32 params) { glPolyFmt(params); }
void __wrap_glFogShift(int shift) { glFogShift(shift); }
void __wrap_glFogOffset(int offset) { glFogOffset(offset); }
void __wrap_glFogColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) { glFogColor(red, green, blue, alpha); }
void __wrap_glFogDensity(int index, int density) { glFogDensity(index, density); }
void __wrap_glLoadMatrix4x4(const m4x4 *m) { glLoadMatrix4x4(m); }
void __wrap_glLoadMatrix4x3(const m4x3 *m) { glLoadMatrix4x3(m); }
void __wrap_glMultMatrix4x4(const m4x4 *m) { glMultMatrix4x4(m); }
void __wrap_glMultMatrix4x3(const m4x3 *m) { glMultMatrix4x3(m); }
void __wrap_glMultMatrix3x3(const m3x3 *m) { glMultMatrix3x3(m); }
void __wrap_glRotateXi(int angle) { glRotateXi(angle); }
void __wrap_glRotateYi(int angle) { glRotateYi(angle); }
void __wrap_glRotateZi(int angle) { glRotateZi(angle); }
void __wrap_glSetOutlineColor(int id, rgb color) { glSetOutlineColor(id, color); }
void __wrap_glSetToonTable(const uint16_t *table) { glSetToonTable(table); }
void __wrap_glSetToonTableRange(int start, int end, rgb color) { glSetToonTableRange(start, end, color); }
void __wrap_glAlphaFunc(int alphaThreshold) { glAlphaFunc(alphaThreshold); }
void __wrap_glCutoffDepth(fixed12d3 wVal) { glCutoffDepth(wVal); }
u32 __wrap_POLY_ALPHA(u32 n) { return POLY_ALPHA(n); }
u32 __wrap_POLY_ID(u32 n) { return POLY_ID(n); }

// Macro wrappers (pointer-returning macros that bindgen can't translate)
u16* __wrap_BG_PALETTE(void) { return BG_PALETTE; }
u16* __wrap_BG_PALETTE_SUB(void) { return BG_PALETTE_SUB; }
u16* __wrap_SPRITE_PALETTE(void) { return SPRITE_PALETTE; }
u16* __wrap_SPRITE_PALETTE_SUB(void) { return SPRITE_PALETTE_SUB; }
u16* __wrap_BG_GFX(void) { return BG_GFX; }
u16* __wrap_BG_GFX_SUB(void) { return BG_GFX_SUB; }
u16* __wrap_VRAM_A(void) { return VRAM_A; }
u16* __wrap_VRAM_B(void) { return VRAM_B; }
u16* __wrap_VRAM_C(void) { return VRAM_C; }
u16* __wrap_VRAM_D(void) { return VRAM_D; }
void* __wrap_CHAR_BASE_BLOCK(int n) { return (void*)CHAR_BASE_BLOCK(n); }
void* __wrap_SCREEN_BASE_BLOCK(int n) { return (void*)SCREEN_BASE_BLOCK(n); }
