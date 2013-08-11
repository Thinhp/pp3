/*- vat
 * copyright (c) 2005 Emil Mikulic
 *
 * png: simplified interface to libpng for writing out images
 */

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include "../libpng/png.h"
#include "../libpng/pngconf.h"

#include "png.h"
#include "util.h"

void
write_image(const char *filename, unsigned char *buf,
   const unsigned int width, const unsigned int height)
{
   png_structp png_ptr;
   png_infop info_ptr;
   FILE *fp;
   unsigned int y;

   fp = fopen(filename, "wb");
   if (fp == NULL)
      err(1, "can't open \"%s\" for writing", filename);

   png_ptr = png_create_write_struct(
      PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
   if (png_ptr == NULL)
      errx(1, "png_create_write_struct");

   info_ptr = png_create_info_struct(png_ptr);
   if (info_ptr == NULL)
      errx(1, "png_create_info_struct");

   png_init_io(png_ptr, fp);
   png_set_filter(png_ptr, 0, PNG_ALL_FILTERS);
   png_set_compression_level(png_ptr, Z_BEST_COMPRESSION);
   png_set_IHDR(png_ptr, info_ptr,
      width, height, 8, PNG_COLOR_TYPE_RGB,
      PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT);

   png_write_info(png_ptr, info_ptr);

   for (y=0; y<height; y++)
      png_write_row(png_ptr, buf + y*3*width);

   png_write_end(png_ptr, info_ptr);
   png_destroy_write_struct(&png_ptr, &info_ptr);
   fclose(fp);
}

void
read_image(const char *filename, unsigned char **buf,
   unsigned int *width, unsigned int *height)
{
   png_structp png_ptr;
   png_infop info_ptr;
   png_infop end_info;
   png_bytep *row_pointers;
   FILE *fp;
   unsigned int y;

   fp = fopen(filename, "rb");
   if (fp == NULL)
      err(1, "can't open \"%s\" for reading", filename);

   png_ptr = png_create_read_struct(
      PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
   if (png_ptr == NULL)
      errx(1, "png_create_read_struct");

   info_ptr = png_create_info_struct(png_ptr);
   if (info_ptr == NULL)
      errx(1, "png_create_info_struct");

   end_info = png_create_info_struct(png_ptr);
   if (end_info == NULL)
      errx(1, "png_create_info_struct");

   if (setjmp(png_jmpbuf(png_ptr)))
      errx(1, "PNG error: libpng did a longjump");

   png_init_io(png_ptr, fp);
   png_read_info(png_ptr, info_ptr);

   png_set_palette_to_rgb(png_ptr);
   png_set_gray_1_2_4_to_8(png_ptr);
   png_set_strip_16(png_ptr);
   png_set_strip_alpha(png_ptr);
   png_set_packing(png_ptr);
   
   if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY ||
         png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
      png_set_gray_to_rgb(png_ptr);
   /*
   png_set_rgb_to_gray_fixed(png_ptr, 1, -1, -1);
   */

   png_read_update_info(png_ptr, info_ptr);

   *width = (unsigned int)png_get_image_width(png_ptr, info_ptr);
   *height = (unsigned int)png_get_image_height(png_ptr, info_ptr);

   if (png_get_bit_depth(png_ptr, info_ptr) != 8)
      errx(1, "PNG must have 8 bits per pixel");

   /*
   if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_GRAY)
      errx(1, "PNG must be grayscale");
   */

   if (png_get_rowbytes(png_ptr, info_ptr) != 3* *width)
      errx(1, "PNG rowbytes != width");

   *buf = (unsigned char*)xmalloc(*width * *height * 3);
   row_pointers = (png_byte**)xmalloc(sizeof(*row_pointers) * *height);
   for (y=0; y<*height; y++)
      row_pointers[y] = *buf + y*(*width * 3);

   png_read_image(png_ptr, row_pointers);
   free(row_pointers);

   png_read_end(png_ptr, end_info);
   png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);

   fclose(fp);
}

/* vim:set tw=78 ts=3 sw=3 et: */
