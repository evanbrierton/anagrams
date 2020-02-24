#include <stddef.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

void error(bool condition, const char * message);
char * newString(size_t length);
char ** newStringArray(size_t arrayLength, size_t stringLength);
char * cleanString(char * str);
char * toLowerCase(char * str);
size_t getStringDiff(char * str1, char * str2);

#endif
