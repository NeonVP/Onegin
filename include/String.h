#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int my_strcmp( const char* lhs, const char* rhs );
void my_strswap( char* str1, char* str2 );

size_t my_strlen ( const char* str );

#endif