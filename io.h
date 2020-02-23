#include <stddef.h>

#ifndef IO_H
#define IO_H

void clearFile(const char * file);
size_t getNLines(const char * file);
size_t getLongestLineLengthLength(const char * file);
void getInput(const char * input, char ** target, size_t lineLength);
void appendToOutput(const char * output, const char * string);
void appendListToOutput(const char * output, size_t lines, char ** strings);

#endif
