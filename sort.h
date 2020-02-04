#include <stdio.h>
#include "config.h"

#ifndef SORT_H
#define SORT_H

void sort(const char strings[N_LINES][LINE_LENGTH], size_t left, size_t right);
char * cloneString(char str[]);
char * newString(size_t length);
char * toLowerCase(char str[]);

#endif