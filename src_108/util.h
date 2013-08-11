/*- vat
 * copyright (c) 2005 Emil Mikulic
 *
 * utilities, convenience functions
 */

#include <stddef.h> /* for size_t */

# ifdef __cplusplus
extern "C" {
# endif

void *xmalloc(const size_t size);
void *xcalloc(const size_t size);
void *xrealloc(void *ptr, const size_t size);

#ifdef __FreeBSD__
# include <err.h>
#else
# define NEED_ERR

void errx(const int status, const char *msg, ...);
void err(const int status, const char *msg, ...);

#endif

# ifdef __cplusplus
}
# endif

/* vim:set tw=78 ts=3 sw=3 et: */
