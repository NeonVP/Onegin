#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "common.h"

void print_help( const char* program_name );

size_t lines_counter( const char* text );
off_t determining_the_file_size( const char * file_name );

void reading_orig_file( FileStat orig_file, char* buffer );
void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines );

void splitting_into_lines( StrPar* string_ptrs, char* text, const size_t nLines );

#endif //