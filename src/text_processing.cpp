#include "text_processing.h"

size_t lines_counter( const char* text ) {
    assert( text != NULL );

    size_t cnt = 0;

    while ( *text != '\0' ) {
        if ( *text == '\n' && *( text + 1 ) != '\n' ) cnt++;

        text++;
    }

    return cnt;
}

void splitting_into_lines( StrPar* strings, char* text, const size_t nLines ) {
    assert( strings != NULL );
    assert( text    != NULL );
    assert( nLines   > 0    );

    for ( size_t i = 0; i < nLines; i++ ) {
        strings[i].ptr = text;

        while ( *text != '\n' ) {
            strings[i].len++;
            text++;
        }

        text++;
    }

    fprintf( stderr, "Find pointers of string begin\n" );
}

void two_sorts_and_output_texts( char* buffer, StrPar* strings, FileStat orig_file, FileStat res_file ) {
    assert( buffer != NULL );
    assert( strings != NULL );

    FILE* file_for_results = fopen( res_file.address, "w" );
    assert( file_for_results != NULL );

    bubble_sort( strings, orig_file.nLines, comparator );
    writing_in_file( file_for_results, strings, orig_file.nLines );
    qsort( ( void* ) strings, orig_file.nLines, sizeof( StrPar ), reverse_comparator );
    writing_in_file( file_for_results, strings, orig_file.nLines );

    fwrite( buffer, sizeof( char ), ( size_t )orig_file.size, file_for_results );
    fprintf( stderr, "Write original Onegin\n" );

    int result_of_fclose = fclose( file_for_results );
    assert( result_of_fclose == 0 );
}