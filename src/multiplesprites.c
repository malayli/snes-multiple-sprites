/*---------------------------------------------------------------------------------


	Multiple sprites demo
	-- malayli


---------------------------------------------------------------------------------*/
#include <snes.h>

extern char gfxpsrite, gfxpsrite_end;
extern char palsprite, palsprite_end;

#define SPRITEADDRESS 		0x2000
#define ADRSPRITLARDGE      0x2400          // arbitrary to have enough space but small & large one
#define PALETTESPRSIZE      (16*2)

int oamId = 0;
int size = 32*32/16;

void loadSprite(int tileIndex, int x, int y, int paletteOffset) {
	oamSet(oamId, x, y, 0, 0, 0, tileIndex, paletteOffset);
	oamSetEx(oamId, OBJ_LARGE, OBJ_SHOW);
	oamId += 4;
}

void loadSprites() {
	int tileIndex = 0;

	// Init Sprites gfx and palette with default size of 32x32
	oamInitGfxSet(&gfxpsrite, (&gfxpsrite_end-&gfxpsrite), &palsprite, (&palsprite_end-&palsprite), 0, SPRITEADDRESS, OBJ_SIZE8_L32);
	
	// Display Sprite 1
	loadSprite(tileIndex, 0, 0, 0);
	loadSprite(tileIndex, 32, 0, 0);
	loadSprite(tileIndex, 64, 0, 0);
	tileIndex += size;
	
	// Display Sprite 2
	loadSprite(tileIndex, 0, 32, 1);
	loadSprite(tileIndex, 32, 32, 1);
	loadSprite(tileIndex, 64, 32, 1);
	tileIndex += size;
	
	// Display Sprite 3
	loadSprite(tileIndex, 0, 64, 2);
	loadSprite(tileIndex, 32, 64, 2);
	loadSprite(tileIndex, 64, 64, 2);
	tileIndex += size;
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
