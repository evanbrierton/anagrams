#include <stddef.h>
#include <stdbool.h>

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

size_t ** generateMap(char ** strings, size_t nLines);
size_t getAnagrams(char ** strings, char ** target, bool (*compare)(char *, char *), size_t nLines, size_t longestLineLength);
bool isAnagram(char * str, char * str2);
bool wouldBeAnagram(char * str1, char * str2);

#endif
