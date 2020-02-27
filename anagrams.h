#include <stddef.h>
#include <stdbool.h>
#include "utils.h"

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

bool isAnagram(char *str, char *str2);
bool isMissingAnagram(char *str1, char *str2);
int ** getAnagrams(char ** strings, bool (*compare)(char *, char *), size_t nLines, size_t longestLineLength);
size_t formatAnagrams(char ** strings, char ** target, int ** matches, size_t maxAnagramLength);
size_t formatMissingAnagrams(char ** strings, char ** target, int ** matches, size_t maxAnagramLength);

#endif
