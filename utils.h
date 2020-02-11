#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H

char * newString(size_t length);
char * cloneString(char str[]);
char * toLowerCase(char str[]);
char * cleanString(char str[]);
void sortString(char str[], size_t left, size_t right);

#endif