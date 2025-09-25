#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "common.h"
#include "io.h"
#include "text_processing.h"

int init( int argc, char* argv[], FileStat* orig_file, FileStat* res_file, char** buffer );


int main( int argc, char* argv[]) {
    FileStat original_file = { "./texts/original_text.txt" };
    FileStat result_file   = { "./texts/result_text.txt"   };
    char* buffer = NULL;

    init( argc, argv, &original_file, &result_file, &buffer );

    reading_orig_file( original_file, buffer );

    original_file.nLines = lines_counter( buffer );
    StrPar* strings = ( StrPar* ) calloc ( original_file.nLines, sizeof( StrPar ) );
    assert( strings != NULL );

    splitting_into_lines( strings, buffer, original_file.nLines );

    two_sorts_and_output_texts( buffer, strings, original_file, result_file );

    free( buffer  );
    free( strings );

    return 0;
}

int init( int argc, char* argv[], FileStat* orig_file, FileStat* res_file, char** buffer ) {
    assert( argc      >  0    );
    assert( argv      != NULL );
    assert( orig_file != NULL );
    assert( res_file  != NULL );
    assert( buffer    != NULL );

    const char* const opts = "i:o:h:";
    int opt = 0;

    while ( ( opt = getopt( argc, argv, opts ) ) != -1 ) {
        switch ( opt ) {
            case 'i':
                orig_file->address = ( const char* ) strdup( optarg );
                break;
            case 'o':
                res_file->address  = ( const char* ) strdup( optarg );
                break;
            case 'h':
                print_help( argv[0] );
                abort();
            default:
                fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
                abort();
        }
    }

    orig_file->size = determining_the_file_size( orig_file->address );

    *buffer = ( char* ) calloc ( (size_t) orig_file->size + 1, sizeof( char ) );
    assert( *buffer != NULL );

    return 0;
}
