#include <stddef.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

void error(bool condition, const char * message);
char * newString(size_t length);
char ** newStringArray(size_t arrayLength, size_t stringLength);
char * slice(char * str, size_t a, size_t b);
int find(char * str, const char * substr);
size_t getStringDiff(char * str1, char * str2);
char * toLowerCase(char * str);
char * cleanString(char * str);
char * removeCharacters(char * str, const char * charactersToRemove);
void sortString(char * str, size_t left, size_t right);

#endif
