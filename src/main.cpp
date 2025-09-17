#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <sys/stat.h>

#include "../include/String.h"

struct StrPar{
    char* ptr;
    size_t len = 0;
};

void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines );

size_t lines_counter( const char* text );

void splitting_into_lines( StrPar* string_ptrs, char* text, const size_t nLines );

void bubble_sort( StrPar* strings, const size_t nLines );
void swap( StrPar* str1, StrPar* str2 );
int comparator( const void* param1, const void* param2 );


int main() {
    const char* file_with_original_text = "./texts/original_text.txt";

    struct stat file_stat;
    stat( file_with_original_text, &file_stat );
    size_t size = ( size_t ) file_stat.st_size;

    char* text = ( char* ) calloc ( size + 1, sizeof( char ) );

    FILE* file = fopen( file_with_original_text, "r" );

    assert( file != NULL );

    fread( text, sizeof( char ), size, file );

    fclose( file );

    size_t nLines = lines_counter( text );

    StrPar* strings = ( StrPar* ) calloc ( nLines, sizeof( StrPar ) );

    assert( strings != NULL );

    splitting_into_lines( strings, text, nLines );

    bubble_sort( strings, nLines );

    for ( unsigned long i = 0; i < nLines; i++ ) {
        printf( "%s\n", strings[i].ptr );
    }

    FILE* file_for_results = fopen( "./texts/result_text.txt", "w" );

    assert( file_for_results != NULL );

    writing_in_file( file_for_results, strings, nLines );

    fclose( file_for_results );

    free( text );
    free( strings );

    return 0;
}


void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines ) {
    assert( file_for_results != NULL );
    assert( strings          != NULL );
    assert( nLines > 0               );

    for ( size_t i = 0; i < nLines; i++ ) {
        fputs( strings[i].ptr, file_for_results );
    }

    fprintf( stderr, "Succesful - write in file\n" );
}

void splitting_into_lines( StrPar* strings, char* text, const size_t nLines ) {
    for ( size_t i = 0; i < nLines; i++ ) {
        strings[i].ptr = text;
        fprintf( stderr, "  text ptr - %p\n", text);
        fprintf( stderr, "string ptr - %p\n", strings[i].ptr);

        while ( *text != '\n' ) {
            strings[i].len++;
            fprintf( stderr, "len - %d\n", ( int ) strings[i].len);
            text++;
        }

        *text++ = '\0';
    }
}

void bubble_sort( StrPar* strings, const size_t nLines ) {
    assert( strings != NULL    );
    assert( isfinite( nLines ) );

    size_t cnt = 1;
    while ( cnt < nLines ) {
        for ( size_t i = 0; i < nLines - cnt; i++ ) {
            int result = strcmp( strings[ i ].ptr, strings[ i + 1 ].ptr );

            if ( result > 0 ) {
                swap( &strings[ i ], &strings[ i + 1 ] );
            }
        }

        cnt++;
    }
}

void swap( StrPar* str1, StrPar* str2 ) {
    assert( str1 != NULL );
    assert( str2 != NULL );

    StrPar str_buf = *str1;
    *str1 = *str2;
    *str2 = str_buf;
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

// int comparator( const void* param1, const void* param2 ) {
//     const char const ** str1 = ( const char const ** ) param1;
//     const char const ** str2 = ( const char const ** ) param2;

//     int diff = 0;

//     while ( **str1 != '\0' && **str2 != '\0' ) {
//         while ( !isalpha( **str1 ) && **str1 != '\0' ) {
//             *str1++;
//         }
//         while ( !isalpha( **str2 ) && **str1 != '\0' ) {
//             *str2++;
//         }

//         diff = **str1 - **str2;

//         if ( diff > 0 ) {
//             return 1;
//         }
//         else if ( diff < 0 ) {
//             return -1;
//         }
//         else {
//             continue;;
//         }
//     }

//     diff = **str1 - **str2;

//     if ( diff > 0 ) {
//         return 1;
//     }
//     else if ( diff < 0 ) {
//         return -1;
//     }
//     else {
//         return 0;
//     }
// }