#include <stddef.h>
#include "utils.h"

#ifndef IO_H
#define IO_H

void clearFile(const string file);
size_t getNLines(const string file);
size_t getLongestLineLengthLength(const string file);
void getInput(const string input, string * target, size_t lineLength);
void appendToOutput(const string output, const string string);
void appendListToOutput(const string output, size_t lines, string * strings, bool freeStrings);

#endif
