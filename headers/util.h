/*
 * util.h
 *
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

/* Prints str, with extra info (__FILE__ and __LINE__) before returning ret */
void   *retstr  (void        *ret, const char *str, const char *file, const int line);
int     retstri (const int    ret, const char *str, const char *file, const int line);
double  retstrf (const double ret, const char *str, const char *file, const int line);

/* Returns the number of lines in str */
uint64_t line_nb(const char *str);

#endif
