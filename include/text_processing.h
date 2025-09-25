#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "common.h"
#include "sorting.h"
#include "io.h"

void splitting_into_lines( StrPar* strings, char* text, const size_t nLines );
size_t lines_counter( const char* text );

void two_sorts_and_output_texts( char* buffer, StrPar* strings, FileStat orig_file, FileStat res_file );


#endif //TEXT_PROCESSING_H