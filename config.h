#include <stdio.h>

#ifndef CONFIG_H
#define CONFIG_H

size_t getNLines(const char file[]);
size_t getLongestLineLength(const char file[]);

#define N_LINES getNLines("input.txt")
#define LINE_LENGTH getLongestLineLength("input.txt")

#endif
