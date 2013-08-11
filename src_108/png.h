/*- vat
 * copyright (c) 2005 Emil Mikulic
 *
 * png: simplified interface to libpng for writing out images
 */

#ifdef __cplusplus
extern "C" {
#endif

void write_image(const char *filename, unsigned char *buf,
    const unsigned int width, const unsigned int height);

void read_image(const char *filename, unsigned char **buf, unsigned int *width,
    unsigned int *height);

#ifdef __cplusplus
}
#endif

/* vim:set tw=78 ts=3 sw=3 et: */
