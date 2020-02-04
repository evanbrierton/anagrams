#include <stdio.h>
#include "config.h"

#ifndef ANAGRAMS_H
#define ANAGRAMS_H

size_t getAnagrams(char strings[N_LINES][LINE_LENGTH], char target[N_LINES / 2][(LINE_LENGTH + 12 + N_LINES / 10) * N_LINES]);
void processStrings(char target[N_LINES][LINE_LENGTH], char strings[N_LINES][LINE_LENGTH]);

#endif