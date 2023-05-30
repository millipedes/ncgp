#include "include/tic_mark.h"

const char * axis_type_to_string(axis_type type) {
  switch(type) {
    case X: return "x";
    case Y: return "y";
  }
  return NULL;
}

tic_mark init_tic_mark(int height, int width) {
  tic_mark the_tic_mark = calloc(1, sizeof(struct TIC_MARK_T));
  the_tic_mark->height = height;
  the_tic_mark->width = width;
  return the_tic_mark;
}

void debug_tic_mark(tic_mark the_tic_mark) {
  printf("[TIC MARK]: (%d, %d)", the_tic_mark->height, the_tic_mark->width);
}

void write_tic_to_canvas(canvas the_canvas, tic_mark the_tic_mark,
    int centroid_x, int centroid_y, axis_type type, pixel color) {
  // X
  if(!type) {
    for(int i = centroid_y - the_tic_mark->height;
        i < centroid_y + the_tic_mark->height; i++) {
      for(int j = centroid_x - the_tic_mark->width;
          j < centroid_x + the_tic_mark->width; j++) {
        if(i >= 0 && j >= 0 && j < the_canvas->width
            && i < the_canvas->height) {
          change_color(the_canvas->values[i][j], color);
        }
      }
    }
  // Y
  } else {
    for(int i = centroid_x - the_tic_mark->width;
        i < centroid_x + the_tic_mark->width; i++) {
      for(int j = centroid_y - the_tic_mark->height;
          j < centroid_y + the_tic_mark->height; j++) {
        if(i >= 0 && j >= 0 && j < the_canvas->width
            && i < the_canvas->height) {
          change_color(the_canvas->values[i][j], color);
        }
      }
    }
  }
}

void free_tic_mark(tic_mark the_tic_mark) {
  if(the_tic_mark)
    free(the_tic_mark);
}
