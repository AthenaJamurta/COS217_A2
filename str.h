#include <stddef.h>
#ifndef STR_INCLUDED
#define STR_INCLUDED

size_t Str_getLength(const char pcString[]);

char *Str_copy(char pcs1[], const char pcs2[]);

char *Str_concat(char pcs1[], const char pcs2[]);

int Str_compare(char pcs1[], const char pcs2[]);

char Str_search(const char pcs1[], const char pcs2[]);

#endif




