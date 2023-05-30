#include "include/axis_title.h"


void write_title(char* path_to_font, char* title, int font_size, int offset,
    canvas the_canvas, pixel color) {
  FT_Library ft;
  FT_Init_FreeType(&ft);
  FT_Face face;
  FT_New_Face(ft, path_to_font, 0, &face);
  FT_Set_Pixel_Sizes(face, 0, font_size);
  
  int total_width = 0;
  int max_ascender = 0;
  int max_descender = 0;

  for (int i = 0; i < TITLE_LEN(title); i++) {
    FT_Load_Char(face, (int)title[i], FT_LOAD_RENDER);
    FT_GlyphSlot slot = face->glyph;
    total_width += slot->bitmap.width;

    if (slot->bitmap_top > max_ascender) {
      max_ascender = slot->bitmap_top;
    }

    if ((int)(slot->bitmap.rows - slot->bitmap_top) > max_descender) {
      max_descender = slot->bitmap.rows - slot->bitmap_top;
    }
  }
  
  int x_offset = (the_canvas->width - total_width) / 2;
  int y_offset = the_canvas->height - offset + max_ascender - max_descender;

  for (int i = 0; i < TITLE_LEN(title); i++) {
    FT_Load_Char(face, (int)title[i], FT_LOAD_RENDER);
    FT_GlyphSlot slot = face->glyph;

    int y_min = y_offset - slot->bitmap_top;
    int y_max = y_min + slot->bitmap.rows;
    int x_min = x_offset;
    int x_max = x_offset + slot->bitmap.width;

    for (int j = y_min, bitmap_y = 0; j < y_max; j++, bitmap_y++) {
      for (int k = x_min, bitmap_x = 0; k < x_max; k++, bitmap_x++) {
        if (slot->bitmap.buffer[bitmap_y * slot->bitmap.width + bitmap_x] > 0) {
          if (j >= 0 && j < the_canvas->height && k >= 0
              && k < the_canvas->width) {
            change_color(the_canvas->values[j][k], color);
          }
        }
      }
    }

    x_offset += slot->bitmap.width;
  }
  
  // Free the FreeType resources
  FT_Done_Face(face);
  FT_Done_FreeType(ft);
}
