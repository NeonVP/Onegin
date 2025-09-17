#include "../include/String.h"

int my_strcmp( const char* lhs, const char* rhs ) {
    assert( lhs != NULL );
    assert( rhs != NULL );

    while ( *lhs != '\0' && *rhs != '\0' && tolower( *lhs ) == tolower( *rhs ) ) {
    // //     go_to_alpha( &str1 );
    // //     go_to_alpha( &str2 );
        if ( !isalpha( *lhs ) ) {
            lhs++;
            continue;
        }
        if ( !isalpha( *rhs ) ) {
            rhs++;
            continue;
        }

        lhs++;
        rhs++;
    }

    assert( rhs != NULL );
    assert( lhs != NULL );

    int result = *lhs - *rhs;

    return result;
}


void my_strswap( char* str1, char* str2 ) {
    char buf = '\0';

    while ( *str1 != '\0' || *str2 != '\0' ) {
        buf = *str1;
        *str1 = *str2;
        *str2 = buf;

        str1++;
        str2++;
    }
}

size_t my_strlen ( const char* str ) {
    assert ( str != nullptr );

    size_t cnt = 0;

    while ( *str != '\0' ) {
        cnt++;
        str++;
    }

    return cnt;
}
