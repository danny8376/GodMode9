#pragma once

#include "common.h"
#include "tar.h"


// set default font
#ifndef DEFAULT_FONT
#define DEFAULT_FONT           "font_default.frf"
#endif

// known file names inside VRAM0 TAR
#define VRAM0_AUTORUN_GM9      "autorun.gm9"
#define VRAM0_FONT             DEFAULT_FONT
#define VRAM0_SCRIPTS          "scripts"
#define VRAM0_README_MD        "README_internal.md"
#define VRAM0_SPLASH_PNG       FLAVOR "_splash.png"
#define VRAM0_EASTER_BIN       "easter.bin"


#define VRAM0_OFFSET    0x22800000
#define VRAM0_LIMIT     0x00600000

#define TARDATA         ((void*) VRAM0_OFFSET)
#define TARDATA_(off)   ((void*) (u32) (VRAM0_OFFSET + (off)))
#define TARDATA_END     TARDATA_(VRAM0_LIMIT)


#define CheckVram0Tar() \
    (ValidateTarHeader(TARDATA, TARDATA_END) == 0)

#define FirstVTarEntry() \
    TARDATA

#define OffsetVTarEntry(off) \
    TARDATA_(off)

#define NextVTarEntry(tardata) \
    NextTarEntry(tardata, TARDATA_END)

#define GetVTarFileInfo(tardata, fname, fsize, is_dir) \
    GetTarFileInfo(tardata, fname, fsize, is_dir)

#define FindVTarFileInfo(fname, fsize) \
    FindTarFileInfo(TARDATA, TARDATA_END, fname, fsize)
