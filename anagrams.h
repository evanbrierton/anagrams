#include <stdio.h>
#include <stdbool.h>
#include "config.h"

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

size_t getAnagrams(char strings[N_LINES][LINE_LENGTH], char target[N_LINES / 2][MAX_ANAGRAM_LENGTH], bool (*compare)(char *, char *));
void processStrings(char target[N_LINES][LINE_LENGTH], char strings[N_LINES][LINE_LENGTH]);
bool isAnagram(char str1[], char str2[]);
bool wouldBeAnagram(char str1[], char str2[]);

#endif