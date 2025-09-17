#include "../include/sorting.h"

void bubble_sort( StrPar* strings, const size_t nLines ) {
    assert( strings != NULL    );
    assert( isfinite( nLines ) );

    size_t cnt = 1;
    while ( cnt < nLines ) {
        for ( size_t i = 0; i < nLines - cnt; i++ ) {
            int result = first_comparator( ( const void* )&strings[ i ], ( const void* )&strings[ i + 1 ] );
            // int result = strcmp( strings[ i ].ptr, strings[ i + 1 ].ptr );

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

int first_comparator( const void* param1, const void* param2 ) {
    assert( param1 != NULL );
    assert( param2 != NULL );

    const char* str1 = ( ( const StrPar* ) param1 )->ptr;

    const char* str2 = ( ( const StrPar* ) param2 )->ptr;

    assert( str1 != NULL );
    assert( str2 != NULL );

    while ( *str1 != '\0' && *str2 != '\0' && tolower( *str1 ) == tolower( *str2 ) ) {
    // //     go_to_alpha( &str1 );
    // //     go_to_alpha( &str2 );
        if ( !isalpha( *str1 ) ) {
            str1++;
            continue;
        }
        if ( !isalpha( *str2 ) ) {
            str2++;
            continue;
        }

        str1++;
        str2++;
    }

    assert( str1 != NULL );
    assert( str2 != NULL );

    int result = *str1 - *str2;

    return result;
}

int second_comparator( const void* param1, const void* param2 ) {
    assert( param1 != NULL );
    assert( param2 != NULL );

    const char*  str1 = ( ( const StrPar* ) param1 )->ptr;
    const size_t len1 = ( ( const StrPar* ) param1 )->len;
    const char*  str2 = ( ( const StrPar* ) param2 )->ptr;
    const size_t len2 = ( ( const StrPar* ) param2 )->len;

    assert( str1 != NULL );
    assert( str2 != NULL );
    assert( len1 > 0     );
    assert( len2 > 0     );

    const char* index1 = str1 + len1;
    const char* index2 = str2 + len2;

    while ( index1 > str1 && index2 > str2 && tolower( *str1 ) == tolower( *str2 ) ) {
        if ( !isalpha( *index1 ) ) {
            index1--;
            continue;
        }

        if ( !isalpha( *index2 ) ) {
            index2--;
            continue;
        }

        index1--;
        index2--;
    }


    assert( str1 != NULL );
    assert( str2 != NULL );

    int result = *index1 - *index2;

    return result;
}