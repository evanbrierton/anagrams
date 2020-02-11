#include <stdio.h>
#include "config.h"

#ifndef IO_H
#define IO_H

void getInput(const char input[], char target[][LINE_LENGTH]);
void clearFile(const char file[]);
void appendToOutput(const char output[], const char string[]);
void appendListToOutput(const char output[], size_t lines, size_t linelength, char strings[][linelength]);

#endif
