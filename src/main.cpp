#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <sys/stat.h>

#include "../include/common.h"
#include "../include/String.h"
#include "../include/sorting.h"
#include "../include/iostream.h"

struct Files {
    const char* original_text;
    const char* result_text;
};


int main() {
    Files files =
    {
        "./texts/original_text.txt",
        "./texts/result_text.txt"
    };

    FILE* file = fopen( files.original_text, "r" );

    struct stat file_stat;
    stat( files.original_text, &file_stat );
    off_t size = file_stat.st_size;

    char* text = ( char* ) calloc ( size + 1, sizeof( char ) );

    assert( file != NULL );

    fread( text, sizeof( char ), size, file );

    fclose( file );

    size_t nLines = lines_counter( text );

    StrPar* strings = ( StrPar* ) calloc ( nLines, sizeof( StrPar ) );

    assert( strings != NULL );

    splitting_into_lines( strings, text, nLines );

    bubble_sort( strings, nLines );

    FILE* file_for_results = fopen( files.result_text, "w" );

    assert( file_for_results != NULL );

    writing_in_file( file_for_results, strings, nLines );

    // qsort( ( void* ) strings, nLines, sizeof( StrPar ), second_comparator );

    // writing_in_file( file_for_results, strings, nLines );

    fclose( file_for_results );

    free( text );
    free( strings );

    return 0;
}
