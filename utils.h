#include <stddef.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

typedef char * string;
void error(bool condition, const string message);
string newString(size_t length);
string * newStringArray(size_t arrayLength, size_t stringLength);
string cleanString(string str);
string toLowerCase(string str);
size_t getStringDiff(string str1, string str2);

#endif
