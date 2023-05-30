#include "include/axis.h"

axis init_axis(int qty_tic_marks, int centroid, int offset, int width,
    pixel color, axis_type type) {
  axis the_axis = calloc(1, sizeof(struct AXIS_T));
  the_axis->qty_tic_marks = 0;
  the_axis->centroid = centroid;
  the_axis->width = width;
  the_axis->color = color;
  the_axis->type = type;
  the_axis->offset = offset;
  for(int i = 0; i < qty_tic_marks; i++)
    the_axis = append_tic_mark(the_axis, init_tic_mark(10, 5));
  return the_axis;
}

GENERIC_ADD_MEMBER(the_axis, axis, tic_marks, the_tic_marks, tic_mark,
    struct TIC_MARK_T, qty_tic_marks)

void write_axis_to_canvas(canvas the_canvas, axis the_axis) {
  for(int i = the_axis->offset; i < the_canvas->height - the_axis->offset;
      i++) {
    for(int j = the_axis->offset; j < the_canvas->width - the_axis->offset;
        j++) {
      if(the_axis->centroid - the_axis->width < (the_axis->type ? j : i)
          && the_axis->centroid + the_axis->width > (the_axis->type ? j : i)) {
        change_color(the_canvas->values[i][j], the_axis->color);
      }
    }
  }
  int tic_mark_incementor
    = ((the_axis->type ? the_canvas->height : the_canvas->width)
        - 2*the_axis->offset) / the_axis->qty_tic_marks;
  for(int i = 0, inc = 0; i < the_axis->qty_tic_marks; i++) {
    inc = i * tic_mark_incementor + the_axis->offset;
    write_tic_to_canvas(the_canvas, the_axis->tic_marks[i], inc,
        the_axis->centroid, the_axis->type, the_axis->color);
  }
}

void debug_axis(axis the_axis) {
  printf("AXIS");
  printf("(qty_tic_marks: %d\ncentroid: %d\nwidth: %d\nType: %s",
      the_axis->qty_tic_marks, the_axis->centroid, the_axis->width,
      axis_type_to_string(the_axis->type));
  debug_pixel(the_axis->color);
}

void free_axis(axis the_axis) {
  if(the_axis) {
    if(the_axis->tic_marks) {
      for(int i = 0; i < the_axis->qty_tic_marks; i++)
        free_tic_mark(the_axis->tic_marks[i]);
      free(the_axis->tic_marks);
    }
    if(the_axis->color)
      free_pixel(the_axis->color);
    free(the_axis);
  }
}
