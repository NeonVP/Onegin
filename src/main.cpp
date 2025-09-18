#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

#include "../include/common.h"
#include "../include/sorting.h"
#include "../include/iostream.h"

struct FilesStats {
    const char* original_text = "\0";
    off_t size_orig_file = 0;
    const char* result_text = "\0";
};


int main() {        //TODO: add command line arguments, function that creates FilesStat, calloc buffer and other, (optional) my qsort
    FilesStats files = {
        "./texts/original_text.txt",
        0,
        "./texts/result_text.txt"
    };

    FILE* file = fopen( files.original_text, "r" );
    assert( file != NULL );

    // TODO: funtion for determining the file size
    files.size_orig_file = determining_the_file_size( files.original_text );

    char* text = ( char* ) calloc ( files.size_orig_file + 1, sizeof( char ) );             //TODO: rename to buffer after sem
    assert( text != NULL );

    fread( text, sizeof( char ), files.size_orig_file, file );

    int result_of_fclose = fclose( file );
    assert( result_of_fclose == 0 );

    size_t nLines = lines_counter( text );

    StrPar* strings = ( StrPar* ) calloc ( nLines, sizeof( StrPar ) );
    assert( strings != NULL );

    splitting_into_lines( strings, text, nLines );

    FILE* file_for_results = fopen( files.result_text, "w" );
    assert( file_for_results != NULL );

    bubble_sort( strings, nLines, ( int (*) ( const void*, const void* ) ) first_comparator );
    writing_in_file( file_for_results, strings, nLines );
    qsort( ( void* ) strings, nLines, sizeof( StrPar ), second_comparator );
    writing_in_file( file_for_results, strings, nLines );
    fwrite( text, sizeof( char ), files.size_orig_file, file_for_results );

    result_of_fclose = fclose( file_for_results );
    assert( result_of_fclose == 0 );

    free( text );
    free( strings );

    return 0;
}


/* nightmare in TXlib.h for goto */