#include <stdio.h>
#include <math.h>

#ifndef CONFIG_H
#define CONFIG_H

#define N_LINES 14
#define LINE_LENGTH 40
#define MAX_N_ANAGRAMS N_LINES / 2
#define MAX_ANAGRAM_LENGTH (size_t)((LINE_LENGTH + 3) * N_LINES + 10 + floor(log10(N_LINES) + 1))
#define MAX_WOULD_BE_ANAGRAM_LENGTH (size_t)(LINE_LENGTH * 2 + 46 + floor(log10(LINE_LENGTH) + 1))

size_t getNLines(const char file[]);
size_t getLongestLineLength(const char file[]);

#endif
