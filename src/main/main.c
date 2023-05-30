#include "../presets/include/axis.h"

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  axis the_axis = init_axis(15, the_canvas->height / 2, 5, init_pixel(0, 0, 0), X);
  axis the_axis_two = init_axis(15, the_canvas->width / 2, 5, init_pixel(0, 0, 0), Y);
  write_axis_to_canvas(the_canvas, the_axis);
  write_axis_to_canvas(the_canvas, the_axis_two);
  write_canvas_png(the_canvas, "test.png");
  free_canvas(the_canvas);
  free_axis(the_axis);
  free_axis(the_axis_two);
  return 0;
}