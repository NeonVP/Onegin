#ifndef IOSTREAM_H
#define IOSTREAM_H

#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "../include/common.h"

off_t determining_the_file_size( const char * file_name );

void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines );

size_t lines_counter( const char* text );

void splitting_into_lines( StrPar* string_ptrs, char* text, const size_t nLines );

#endif