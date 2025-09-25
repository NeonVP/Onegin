#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

#include "common.h"

off_t determining_the_file_size( const char * file_name );

void reading_orig_file( FileStat orig_file, char* buffer );
void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines );

void print_help( const char* program_name );

#endif //IO_H