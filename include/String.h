#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int my_puts ( const char * string );

int my_strcmp( const char* lhs, const char* rhs );
void my_strswap( char* str1, char* str2 );

const char* my_strchr ( const char* str, int ch );

size_t my_strlen ( const char* str );

char* my_strcpy  ( char* dest, const char* src );
char* my_strncpy ( char* s1, char* s2, size_t n );

char* my_strcat  ( char* dest, const char* src );
char* my_strncat (char* dest, const char* src, int n);

int my_atoi ( const char* str );

char* my_fgets ( char* str, int numChars, FILE* stream );

char* my_strdup ( const char* src );

ssize_t my_getline( char** lineptr, size_t* n, FILE* stream );

#endif