#ifndef BOR_H
#define BOR_H

#include "../../canvas/include/canvas.h"

typedef struct BORDER_T {
  pixel color;
  int width;
  int offset;
} * border;

border init_border(pixel color, int width, int offset);
void write_border_to_canvas(canvas the_canvas, border the_border);
void debug_border(border the_border);
void free_border(border the_border);

#endif
