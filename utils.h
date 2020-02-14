#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H

char * newString(size_t length);
char * slice(char str[], size_t a, size_t b);
char * getShortestString(char str1[], char str2[], const char charactersToIgnore[]);
char * getLongestString(char str1[], char str2[], const char charactersToIgnore[]);
char * cloneString(char str[]);
char * toLowerCase(char str[]);
char * cleanString(char str[]);
void sortString(char str[], size_t left, size_t right);

#endif