#include "include/border.h"

border init_border(pixel color, int width, int offset) {
  border the_border = calloc(1, sizeof(struct BORDER_T));
  the_border->width = width;
  the_border->offset = offset;
  the_border->color = color;
  return the_border;
}

void write_border_to_canvas(canvas the_canvas, border the_border) {
  for(int i = the_border->offset; i < the_canvas->height - the_border->offset;
      i++) {
    for(int j = the_border->offset; j < the_canvas->width - the_border->offset;
        j++) {
      if(j <= the_border->offset + the_border->width
          || i <= the_border->offset + the_border->width
          || i >= the_canvas->height - the_border->width - the_border->offset
          || j >= the_canvas->width - the_border->width - the_border->offset)
        change_color(the_canvas->values[i][j], the_border->color);
    }
  }
}

void debug_border(border the_border) {
  printf("BORDER: (%d, %d)\n", the_border->width, the_border->offset);
}

void free_border(border the_border) {
  if(the_border) {
    if(the_border->color)
      free_pixel(the_border->color);
    free(the_border);
  }
}
