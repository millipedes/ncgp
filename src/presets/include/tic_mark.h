#ifndef TIC_H
#define TIC_H

#include "../../canvas/include/canvas.h"

typedef enum {
  X,
  Y
} axis_type;

const char * axis_type_to_string(axis_type type);

typedef struct TIC_MARK_T {
  int height;
  int width;
} * tic_mark;

tic_mark init_tic_mark(int height, int width);
void debug_tic_mark(tic_mark the_tic_mark);
void write_tic_to_canvas(canvas the_canvas, tic_mark the_tic_mark,
    int centroid_x, int centroid_y, axis_type type, pixel color);
void free_tic_mark(tic_mark the_tic_mark);

#endif
