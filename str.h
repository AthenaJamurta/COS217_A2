#include <stddef.h>
#ifndef STR_INCLUDED
#define STR_INCLUDED


/* The Str_getLength function takes a constant char array pcString[] as a parameter
 that represents a string and outputs the length of the string array as a
 size_t return value. Str_getLength asserts that the pcString[] parameter is not
 null. If it is null, then the function writes a message to stderr.*/
size_t Str_getLength(const char pcString[]);


/* The Str_copy function takes a char array pcs1[] and a constant char array pcs2[]
 that both represent a string and outputs a char* return value that is specified by
 pcs1[], after copying pcs2 into the location specified by pcs1. Str_copy asserts that
 the input parameters, pcs1 and pcs2, are not null. If one of them is null, then the
 function writes a message to stderr.*/
char *Str_copy(char pcs1[], const char pcs2[]);


/* The Str_concat function takes a char array pcs1[] and a constant char array pcs2[]
 that both represent a string and outputs a char* return value. The function concatenates
 the pcs1 and pcs2 strings, storing the concatenation in pcs1, which is what is returned.
 Str_concat asserts that the input parameters, pcs1 and pcs2, are not null. If one of them
 is null, then the function writes a message to stderr. */
char *Str_concat(char pcs1[], const char pcs2[]);


/* The Str_concat function takes a char array pcs1[] and a constant char array pcs2[]
 that both represent a string and outputs an integer return value. The function compares
 the two strings by comparing their characters and returns 0 if they are equal. Str_compare
 asserts that the input parameters, pcs1 and pcs2, are not null. If one of them
 is null, then the function writes a message to stderr.*/
int Str_compare(char pcs1[], const char pcs2[]);


/* */
char Str_search(const char pcs1[], const char pcs2[]);

#endif




