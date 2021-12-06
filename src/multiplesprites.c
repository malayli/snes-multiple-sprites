/*---------------------------------------------------------------------------------


    Multiple sprites demo
    -- malayli


---------------------------------------------------------------------------------*/
#include <snes.h>

extern char gfxpsrite, gfxpsrite_end;
extern char palsprite, palsprite_end;

#define SPRITEADDRESS       0x2000
#define LARGESPRITEADDRESS  0x2400          // arbitrary to have enough space but small & large one
#define PALETTESPRSIZE      (16*2)

#define PAL0 0
#define PAL1 1
#define PAL2 2

// The oam number to be set [0 - 127] * 4 because of oam structures
u16 oamId = 0;

// Tile size
u16 tileSize = 32*32/16;

// Tilenumber graphic offset
u16 gfxoffset = 0;

void loadSprite(u16 x, u16 y, u16 gfxoffset, int paletteoffset) {
    oamSet(oamId, x, y, 0, 0, 0, gfxoffset, paletteoffset);
    oamSetEx(oamId, OBJ_LARGE, OBJ_SHOW);
    oamId += 4;
}

void loadSpritesAtLine(u16 lineNumber, u16 gfxoffset, int paletteoffset) {
    int i;
    for (i = 0; i<8; i++) {
        loadSprite(i*32, lineNumber, gfxoffset, paletteoffset);
    }
}

void loadSprites() {
    // Init Sprites gfx and palette with default size of 32x32
    oamInitGfxSet(&gfxpsrite, (&gfxpsrite_end-&gfxpsrite), &palsprite, (&palsprite_end-&palsprite), 0, SPRITEADDRESS, OBJ_SIZE8_L32);

    loadSpritesAtLine(0, gfxoffset, PAL0);
    gfxoffset += tileSize;

    loadSpritesAtLine(32, gfxoffset, PAL1);
    gfxoffset += tileSize;

    loadSpritesAtLine(64, gfxoffset, PAL2);
    gfxoffset += tileSize;
}

//---------------------------------------------------------------------------------
int main(void) {
    // Initialize SNES
    consoleInit();

    loadSprites();

    // Now Put in 16 color mode and disable all backgrounds
    setMode(BG_MODE1,0); bgSetDisable(0); bgSetDisable(1); bgSetDisable(2);
    setScreenOn();

    // Wait for nothing :P
    while(1) {
        // Wait VBL 'and update sprites too ;-) )
        WaitForVBlank();
    }
    return 0;
}
