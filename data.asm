.include "hdr.asm"

.section ".rodata1" superfree

gfxpsrite:
.incbin "sprite1.pic"
.incbin "sprite2.pic"
.incbin "sprite3.pic"
gfxpsrite_end:

palsprite:
.incbin "sprite1.pal"
.incbin "sprite2.pal"
.incbin "sprite3.pal"
palsprite_end:

.ends
