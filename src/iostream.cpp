#include "../include/iostream.h"

void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines ) {
    assert( file_for_results != NULL );
    assert( strings          != NULL );
    assert( nLines > 0               );

    for ( size_t i = 0; i < nLines; i++ ) {
       fwrite( strings[i].ptr, sizeof( char ), strings[i].len, file_for_results );
    }

    fputs( "\n\n", file_for_results );
}

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
}