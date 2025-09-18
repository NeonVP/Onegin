#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include "colors.h"

#define MyAssert( arg, err_code ) if ( !arg ) { printerr( __FILE__, __func__, __LINE__, err_code ); return err_code; }
#define IS_ERR_NONE(err) if (!err == ERR_NONE) { return 1; } // 1? what is it???

enum Errors {
    ERR_NONE = 0,
    ERR_NULLPTR = 1,
    ERR_ISINFINITE = 2
};

void printerr(const char file[], const char func[], int const line, Errors const err_code);

#endif
