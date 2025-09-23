#include "io.h"


void reading_orig_file( FileStat orig_file, char* buffer ) {
    FILE* file = fopen( orig_file.address, "r" );

    size_t result_of_read = fread( buffer, sizeof( char ), ( size_t )orig_file.size, file );
    assert( result_of_read   != 0 );

    int result_of_fclose = fclose( file );
    assert( result_of_fclose == 0 );
}

void writing_in_file( FILE* file_for_results, StrPar* strings, const size_t nLines ) {
    assert( file_for_results != NULL );
    assert( strings          != NULL );
    assert( nLines > 0               );

    for ( size_t i = 0; i < nLines; i++ ) {
       fwrite( strings[i].ptr, sizeof( char ), strings[i].len, file_for_results );
    }

    fputs( "\n\n", file_for_results );

    fprintf( stderr, "Write Onegin in file\n" );
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

    fprintf( stderr, "Find pointers of string begin\n" );
}

off_t determining_the_file_size( const char * file_name ) {
    struct stat file_stat;
    int check_stat = stat( file_name, &file_stat );
    assert( check_stat == 0 );

    return file_stat.st_size;
}

void print_help( const char* program_name ) {
    fprintf( stderr, "Usage: %s [OPTIONS] [FILE...]\n"
                     "Options:\n"
                     "  -h, --help          Display this help message\n"
                     "  -i, --input FILE    Set input file  ( default: ./texts/original_text.txt )\n"
                     "  -o, --output FILE   Set output file ( default: ./texts/result_text.txt )\n",
             program_name );
}