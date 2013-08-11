/*- vat
 * copyright (c) 2005 Emil Mikulic
 *
 * utilities, convenience functions
 */
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#ifdef NEED_ERR
#include <errno.h>
#include <stdarg.h>
#include <string.h>
/* errx - prints "error: [...]\n" to stderr and exit()s with [code]
 * Replacement for the BSD errx() which is usually in <err.h>
 */
void errx(const int code, const char *format, ...)
{
  va_list va;
  va_start(va, format);
  fprintf(stderr, "error: ");
  vfprintf(stderr, format, va);
  fprintf(stderr, "\n");
  va_end(va);
  exit(code);
}

/* err - prints "error: [...]: strerror\n" to stderr and exit()s with [code]
 * Replacement for the BSD err() which is usually in <err.h>
 */
void err(const int code, const char *format, ...)
{
  va_list va;
  va_start(va, format);
  fprintf(stderr, "error: ");
  vfprintf(stderr, format, va);
  fprintf(stderr, ": %s\n", strerror(errno));
  va_end(va);
  exit(code);
}
#endif

void * xmalloc(const size_t size)
{
  void *ptr = malloc(size);
  if (ptr == NULL)
    errx(1, "ran out of memory in xmalloc");
  return (ptr);
}

void * xcalloc(const size_t size)
{
  void *ptr = calloc(1, size);
  if (ptr == NULL)
    errx(1, "ran out of memory in xcalloc");
  return (ptr);
}

void * xrealloc(void *ptr, const size_t size)
{
  void *ret = realloc(ptr, size);
  if (ret == NULL)
    errx(1, "ran out of memory in xrealloc");
  return (ret);
}

/* vim:set tw=78 ts=3 sw=3 et: */

