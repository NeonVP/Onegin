#ifndef SORTING_H
#define SORTING_H

#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "common.h"

void bubble_sort( StrPar* strings, const size_t nLines, int ( *comparator ) ( const void*, const void* ) );
void swap( StrPar* str1, StrPar* str2 );

int comparator ( const void* param1, const void* param2 );
int reverse_comparator( const void* param1, const void* param2 );

#endif