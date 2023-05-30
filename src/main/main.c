#include "../presets/include/axis.h"
#include "../presets/include/border.h"
#include "../presets/include/axis_title.h"

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  axis the_axis = init_axis(15, the_canvas->height / 2, 50, 5, init_pixel(0, 0, 0), X);
  axis the_axis_two = init_axis(15, the_canvas->width / 2, 50, 5, init_pixel(0, 0, 0), Y);
  border the_border = init_border(init_pixel(0, 0, 0), 5, 45);
  write_axis_to_canvas(the_canvas, the_axis);
  write_axis_to_canvas(the_canvas, the_axis_two);
  write_border_to_canvas(the_canvas, the_border);
  pixel tmp_pixel = init_pixel(0, 0, 0);
  write_title("./font/FiraCode-Bold.ttf", "Test Title", 24, 40, the_canvas, tmp_pixel);
  free_pixel(tmp_pixel);
  write_canvas_png(the_canvas, "test.png");
  free_canvas(the_canvas);
  free_axis(the_axis);
  free_axis(the_axis_two);
  free_border(the_border);
  return 0;
}
