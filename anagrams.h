#include <stddef.h>
#include <stdbool.h>

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

bool isAnagram(char * str, char * str2);
bool wouldBeAnagram(char * str1, char * str2);
size_t getAnagrams(char ** strings, char ** target, bool (*compare)(char *, char *), size_t nLines, size_t longestLineLength);
void formatAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength);
size_t formatWouldBeAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength);


#endif
