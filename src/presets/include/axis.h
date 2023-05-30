#ifndef AXI_H
#define AXI_H

#include "../../main/include/constants_macros.h"
#include "tic_mark.h"

typedef struct AXIS_T {
  tic_mark * tic_marks;
  pixel color;
  axis_type type;
  int qty_tic_marks;
  int centroid;
  int width; // This is 2*width
  int offset;
} * axis;

axis init_axis(int qty_tic_marks, int centroid, int offset, int width,
    pixel color, axis_type type);
void write_axis_to_canvas(canvas the_canvas, axis the_axis);
axis append_tic_mark(axis the_axis, tic_mark the_tic_mark);
void debug_axis(axis the_axis);
void free_axis(axis the_axis);

#endif
