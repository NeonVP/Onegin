#include "../include/errors.h"

const char* errormessage[] = {"No errors", "Null Pointer", "An infinite number"};

void printerr(const char file[], const char func[], int const line, Errors const err_code) {
    fprintf(stderr, COLOR_RED "Error in file: %s, function: %s and line: %d - %s\n" COLOR_RESET, file, func, line, errormessage[err_code]);
}