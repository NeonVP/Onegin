#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../include/String.h"

void reading_file( FILE* file, char** text, const long nLines );
void writing_in_file( FILE* file_for_results, char** text, const long nLines );

void free_text( char** text, const long nLines );

long lines_counter( FILE* file );

void bubble_sort_strings( char** text, const long nLines );
void swap( char** str1, char** str2 );


int main() {
    FILE* file = fopen( "./texts/original_text.txt", "r" );

    if ( file == NULL ) {
        fprintf( stderr, "Fail - open file\n" );
        return 1;
    }
    else {
        fprintf( stderr, "Succesful - open file\n" );
    }

    long nLines = lines_counter( file );

    char** text = ( char** ) calloc ( ( size_t )nLines, sizeof( char* ) );

    if ( text == NULL ) {
        fprintf( stderr, "Fail - allocate memory for the text\n" );
        return 1;
    }
    else {
        fprintf(stderr, "Succesful - allocate memory for the text\n" );
    }

    reading_file( file, text, nLines );

    fclose( file );

    FILE* file_for_results = fopen( "./texts/result_text.txt", "w" );

    if ( file == NULL ) {
        fprintf( stderr, "Fail - open file\n" );
        return 1;
    }
    else {
        fprintf( stderr, "Succesful - open file\n" );
    }

    bubble_sort_strings( text, nLines );

    writing_in_file( file_for_results, text, nLines );

    fclose( file_for_results );
    free_text( text, nLines );

    return 0;
}


void reading_file( FILE* file, char** text, const long nLines ) {
    assert( file != NULL     );
    assert( text != NULL     );
    assert( isfinite( NULL ) );

    char str[100] = "\0";

    for ( long int i = 0; i < nLines; i++ ) {
        fgets( str, 100, file );
        *(text + i) = strdup( str );
    }
}

void writing_in_file( FILE* file_for_results, char** text, const long nLines ) {
    assert( file_for_results != NULL );
    assert( text             != NULL );
    assert( isfinite( nLines )       );

    for ( int i = 0; i < nLines; i++ ) {
        fputs( text[i], file_for_results );
    }

    fprintf( stderr, "Succesful - write in file\n" );
}

void free_text( char** text, const long nLines ) {
    assert( text != NULL       );
    assert( isfinite( nLines ) );

    for ( long int i = 0; i < nLines; i++ ) {
        free( text[i] );
    }

    free( text );
}

void bubble_sort_strings( char** text, const long nLines ) {
    assert( text != NULL       );
    assert( isfinite( nLines ) );

    int cnt = 1;
    while ( cnt < nLines ) {
        for ( int i = 0; i < nLines - cnt; i++ ) {
            int result = my_strcmp( text[ i ], text[ i + 1 ] );

            if ( result > 0 ) {
                swap( &text[ i ], &text[ i + 1 ] );
            }
        }

        cnt++;
    }
}

void swap( char** str1, char** str2 ) {
    assert( str1 != NULL );
    assert( str2 != NULL );

    char* str_buf = *str1;
    *str1 = *str2;
    *str2 = str_buf;
}

long lines_counter( FILE* file ) {
    assert( file != NULL );

    long cnt = 0;
    int ch = 0;

    while ( ( ch = fgetc( file ) ) != EOF ) {
        if ( ch == '\n' ) cnt++;
    }

    rewind( file );

    return cnt;
}
