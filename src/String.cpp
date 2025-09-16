#include "../include/String.h"


int my_puts ( const char * string ) {
    assert ( string != nullptr );

    while ( *string != '\0' ) {
        putchar ( *string++ );
    }
    printf ( "\n" );

    return 0;
}

/* being recycled*/
// int my_strcmp( const char* lhs, const char* rhs ) {
//     while ( *lhs != '\0' && *rhs != '\0' ) {
//         if ( *lhs - *rhs == 0 ) {
//             continue;
//         }
//         else if ( *lhs - *rhs > 0 ) {
//             return 1;
//         }
//         else {
//             return -1;
//         }

//         lhs++;
//         rhs++;
//     }

//     return 0;
// }


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

const char* my_strchr ( const char* str, int ch ) {
    assert ( str != nullptr  );
    assert ( isfinite ( ch ) );

    while ( *str != ch && *str != '\0' ) {
        str++;
    }

    if ( *str == ch ) {
        return str;
    }
    else {
        return NULL;
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

char* my_strcpy( char* dest, const char* src ) {
    assert ( dest != NULL );
    assert ( src  != NULL );

    // fprintf(stderr, "%s\n", src);

    char * const old_dest = dest;

    while ( *src != '\0' ) {
        *dest++ = *src++;
    }

    *dest = '\0';

    return old_dest;
}

char* my_strncpy ( char* s1, char* s2, size_t n ) {
    assert ( s1 != nullptr  );
    assert ( s2 != nullptr  );
    assert ( isfinite ( n ) );

    char * const old_s1 = s1;

    while ( n != 0 && *s2 != '\0' ) {
        *s1 = *s2;

        n--;
        s1++;
        s2++;
    }

    while ( n != 0) {
        *s1 = '\0';

        s1++;
        n--;
    }

    return old_s1;
}

char* my_strcat ( char* dest, const char* src ) {
    assert ( dest != nullptr );
    assert ( src  != nullptr );

    char * const old_dest = dest;

    while ( *dest != '\0' ) {
        dest++;
    }

    while ( *src != '\0' ) {
        *dest = *src;

        dest++;
        src++;
    }

    return old_dest;
}

char* my_strncat ( char* dest, const char* src, int n ) {
    assert ( dest != nullptr );
    assert ( src  != nullptr );
    assert ( isfinite ( n )  );

    char * const old_dest = dest;

    while ( *dest != '\0' ) {
        dest++;
    }

    while ( *src != '\0' && n != 0 ) {
        *dest = *src;

        dest++;
        src++;
        n--;
    }

    return old_dest;
}

int my_atoi ( const char* str ) {
    assert ( str != nullptr );

    while ( *str == ' ' ) {
        str++;
    }

    int sign = 1;
    if ( *str == '-' ) {
        sign = -1;
        str++;
    }

    int number = 0;
    while ( isdigit ( *str ) ) {
        number *= 10;
        number += *str - 48;

        str++;
    }

    return sign * number;
}

char* my_fgets ( char* str, int numChars, FILE* stream ) {
    assert ( str    != nullptr     );
    assert ( stream != nullptr     );
    assert ( isfinite ( numChars ) );

    char * const old_str = str;

    if ( str == nullptr || numChars <= 0 || stream == nullptr ) {
        return NULL;
    }

    char ch = '\0';

    while ( (ch = ( char ) fgetc ( stream )) != '\n' && ch != EOF && numChars > 0 ) {
        *str = ch;
        str++;
        numChars--;
    }

    if ( ch == EOF && numChars != 0 ) {
        return NULL;
    }

    return old_str;
}

char* my_strdup ( const char* src ) {
    assert ( src != nullptr );

    char* str_for_copy = ( char * ) calloc ( strlen( src ) + 1, sizeof ( char ) );

    if ( str_for_copy == NULL ) {
        return NULL;
    }
    else {
        str_for_copy = my_strcpy(str_for_copy, src);
        return str_for_copy;
    }
}

ssize_t my_getline( char** lineptr, size_t* size, FILE* stream ) {
    if ( lineptr == NULL || size == NULL || stream == NULL ) {
        return EINVAL;
    }

    printf ( "start my_getline\n" );

    if ( *lineptr == NULL ) {
        *lineptr = ( char * ) calloc ( *size + 2, 8 );
        if ( *lineptr == NULL ) {
            return ENOMEM;
        }

        printf ( "done calloc\n" );
    }

    int cnt_ch = 0;
    char ch = '\0';

    printf ( "start while\n" );
    while ( (ch = ( char ) fgetc ( stream )) != '\n' && ch != EOF ) {
        ( *lineptr ) [ cnt_ch ] = ch;
        cnt_ch++;
        printf ( "%d char - %c\n", cnt_ch, ch );

        printf ( "check for size\n" );
        if ( cnt_ch + 1 == ( int ) *size ) {
            printf ( "criticial size\n" );
            *size = *size * 2;
            *lineptr = ( char * ) realloc ( *lineptr, *size + 2 );

            if ( *lineptr == NULL ) {
                return ENOMEM;
            }
        }
    }

    if ( ch == EOF ) {
        return -1;
    }

    return cnt_ch + 1;
}
