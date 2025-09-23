#include "sorting.h"

void bubble_sort( StrPar* strings, const size_t nLines, int ( *comparator ) ( const void*, const void* ) ) {
    assert( strings != NULL    );
    assert( nLines > 0         );
    assert( comparator != NULL );

    size_t cnt = 1;
    while ( cnt < nLines ) {
        for ( size_t i = 0; i < nLines - cnt; i++ ) {
            int result = comparator( ( const void* )&strings[ i ], ( const void* )&strings[ i + 1 ] );

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

    const char*  str1 = ( ( const StrPar* ) param1 )->ptr;
    // const size_t len1 = ( ( const StrPar* ) param1 )->len;
    const char*  str2 = ( ( const StrPar* ) param2 )->ptr;
    // const size_t len2 = ( ( const StrPar* ) param2 )->len;

    assert( str1 != NULL );
    assert( str2 != NULL );
    // assert( len1 > 0     );
    // assert( len2 > 0     );

    // const char* end1 = str1 + len1;
    // const char* end2 = str2 + len2;

    // TODO: create new function for going to alpha
    while ( !isalpha( *str1 ) && *str1 != '\n' ) {
        str1++;
        continue;
    }
    while ( !isalpha( *str2 ) && *str2 != '\n' ) {
        str2++;
        continue;
    }

    while ( *str1 != '\n' && *str2 != '\n' && tolower( *str1 ) == tolower( *str2 ) ) {
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

    while ( !isalpha( *str1 ) && *str1 != '\n' ) {
        str1++;
        continue;
    }
    while ( !isalpha( *str2 ) && *str2 != '\n' ) {
        str2++;
        continue;
    }

    int result = tolower( *str1 ) - tolower( *str2 );

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

    const char* pointer1 = str1 + len1;
    const char* pointer2 = str2 + len2;

    while ( !isalpha( *pointer1 ) && pointer1 > str1 ) {
        pointer1--;
        continue;
    }
    while ( !isalpha( *pointer2 ) && pointer2 > str2 ) {
        pointer2--;
        continue;
    }

    while ( pointer1 > str1 && pointer2 > str2 && tolower( *pointer1 ) == tolower( *pointer2 ) ) {
        if ( !isalpha( *pointer1 ) ) {
            pointer1--;
            continue;
        }

        if ( !isalpha( *pointer2 ) ) {
            pointer2--;
            continue;
        }

        pointer1--;
        pointer2--;
    }

    assert( pointer1 != NULL );
    assert( pointer2 != NULL );

    int result = 0;

    if ( pointer1 + 1 == str1 && pointer2 + 1 == str2 ) {
        result = 0;
    }
    else if ( pointer1 + 1  == str1 ) {
        result = 0 - tolower( *pointer2 );
    }
    else if ( pointer2 + 1 == str2 ) {
        result = tolower( *pointer1 ) - 0;
    }
    else {
        result = tolower( *pointer1 ) - tolower( *pointer2 );
    }

    return result;
}