#include <stddef.h>

#ifndef IO_H
#define IO_H

void getInput(const char * input, char ** target, size_t lineLength);
void clearFile(const char * file);
void appendToOutput(const char * output, const char * string);
void appendListToOutput(const char * output, size_t lines, char ** strings);
size_t getNLines(const char file[]);
size_t getlongestLineLengthLength(const char file[]);
void formatAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength);
void formatWouldBeAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength);

#endif
