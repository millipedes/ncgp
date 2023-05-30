#ifndef AXT_H
#define AXT_H

#include "../../canvas/include/canvas.h"
#include <string.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#define MAX_TITLE_LEN 32
#define TITLE_LEN(t) (int)strnlen(t, MAX_TITLE_LEN)

void write_title(char * path_to_font, char * title, int font_size, int offset,
    canvas the_canvas, pixel color);

#endif
