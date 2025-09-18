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

struct FilesStats {
    const char* original_text = "./texts/original_text.txt";
    off_t size_orig_file = 0;
    const char* result_text = "./texts/result_text.txt";
};


int main() {
    FilesStats files;

    FILE* file = fopen( files.original_text, "r" );
    assert( file != NULL );

    struct stat file_stat;
    stat( files.original_text, &file_stat );
    files.size_orig_file = file_stat.st_size;

    char* text = ( char* ) calloc ( files.size_orig_file + 1, sizeof( char ) );

    fread( text, sizeof( char ), files.size_orig_file, file );

    assert( fclose( file ) == 0 );

    size_t nLines = lines_counter( text );

    StrPar* strings = ( StrPar* ) calloc ( nLines, sizeof( StrPar ) );

    assert( strings != NULL );

    splitting_into_lines( strings, text, nLines );

    bubble_sort( strings, nLines, ( int (*) ( const void*, const void* ) ) first_comparator );

    FILE* file_for_results = fopen( files.result_text, "w" );

    assert( file_for_results != NULL );

    writing_in_file( file_for_results, strings, nLines );

    fputs( "\n\n", file_for_results );

    qsort( ( void* ) strings, nLines, sizeof( StrPar ), second_comparator );
    // bubble_sort( strings, nLines, second_comparator );

    writing_in_file( file_for_results, strings, nLines );

    assert( fclose( file_for_results ) == 0 );

    free( text );
    free( strings );

    return 0;
}
