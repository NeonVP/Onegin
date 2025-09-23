#ifndef COMMON_H
#define COMMON_H

#include <sys/stat.h>
#include <math.h>

struct StrPar{
    const char* ptr = NULL;
    size_t len = 0;
};

struct FileStat {
    const char* address = "";
    size_t nLines = 0;
    off_t size = 0;
};

#endif