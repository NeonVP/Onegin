#include <stdio.h>
#include <assert.h>


enum str_comp {
    ABOVE = 1,
    EQUAL = 0,
    LESS = -1
};


void reading_file( char text[][ 200 ] );
void writing_in_file( char text[][ 200 ] );

void sort_strings( char text[][ 200 ] );
void str_swap( char* str1, char* str2 );

str_comp string_comparison ( char* str1, char* str2 );


int main() {
    char text[ 5500 ][ 200 ] = { "\0" };

    reading_file    ( text );
    sort_strings    ( text );
    writing_in_file ( text );

    fprintf( stderr, "%s", text[5331] );
    return 0;
}


void reading_file( char text[][ 200 ] ) {
    FILE* file = fopen ( "./texts/original_text.txt", "r" );

    assert ( file != NULL );

    for ( int i = 0; i < 5332; i++ ) {
        printf( "%s - %d\n", fgets( text[i], 200, file ), i );
    }

    fclose ( file );
}

void writing_in_file( char text[][ 200 ] ) {
    FILE* file_for_results = fopen( "./texts/result_text.txt", "w");

    for ( int i = 0; i < 5332; i++ ) {
        fputs( text[i], file_for_results );
    }

    fclose( file_for_results );
}

void sort_strings( char text[][ 200 ] ) {
    int cnt = 0;
    while ( cnt < 5331 ) {
        for ( int i = 0; i < 5331 - cnt; i++ ) {
            string_comparison( text[ i ], text[ i + 1 ] );
        }

        cnt++;
        // fprintf( stderr, "sorted %d\n", cnt );
    }
}

str_comp string_comparison( char* str1, char* str2 ) {
    assert( str1 != NULL );
    assert( str2 != NULL );

    for ( int i = 0; i < 200; i++ ) {
        if ( str1[ i ] > str2[ i ] ) {
            str_swap( str1, str2 );
            return ABOVE;
        }
        else if ( str1[ i ] < str2[ i ] ) {
            return LESS;
        }
        else {
            continue;
        }
    }

    return EQUAL;
}

void str_swap( char* str1, char* str2 ) {
    char buf = '\0';

    while ( *str1 != '\0' || *str2 != '\0' ) {
        buf = *str1;
        *str1 = *str2;
        *str2 = buf;

        str1++;
        str2++;
    }
}