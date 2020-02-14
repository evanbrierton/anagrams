#include <stddef.h>
#include <stdbool.h>

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

size_t getAnagrams(char ** strings, char ** target, bool (*compare)(char *, char *));
bool isAnagram(char str1[], char str2[]);
bool wouldBeAnagram(char str1[], char str2[]);

#endif