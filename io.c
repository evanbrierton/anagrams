#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "utils.h"

// Function to read input from a text file and output each line to a string array
void getInput(const char * input, char ** target, size_t lineLength)
{
    FILE * fp = fopen(input, "r");
    error(!fp, strerror(errno));

    for (size_t i = 0; fgets(target[i], lineLength, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
}

void clearFile(const char * file)
{
    FILE *fp;
    fp = fopen(file, "w");
    error(!fp, strerror(errno));

    fclose(fp);
}

void appendToOutput(const char * output, const char * string)
{
    FILE *fp;
    fp = fopen(output, "a");
    error(!fp, strerror(errno));

    fprintf(fp, "%s\n", string);
    fclose(fp);
}

void appendListToOutput(const char * output, size_t lines, char ** strings)
{
    for (size_t i = 0; i < lines; i++) appendToOutput(output, strings[i]);
}

size_t getNLines(const char * file)
{
    size_t lines = 1;

    FILE *fp;
    fp = fopen(file, "r");
    error(!fp, strerror(errno));

    char lastCharacter = 0;
    for (int c = getc(fp); c != EOF; c = getc(fp))
    {
        lastCharacter = (char)c;
        if (c == '\n') lines++;
    }
    error(lastCharacter != '\n', "Last character must be a newline");
    fclose(fp);
    return lines - 1;
}

size_t getlongestLineLengthLength(const char * file)
{
    size_t length = 0;
    size_t max = 0;
    
    FILE *fp;
    fp = fopen(file, "r");
    error(!fp, strerror(errno));

    for (int c = getc(fp); c != EOF; c = getc(fp))
    {
        length++;
        if (c == '\n')
        {  
            if (length > max) max = length;
            length = 0;
        }
    };
    return max + 2;
}

void formatAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength)
{
    for (size_t i = 0; i < nAnagrams; i++) {
        char * formattedString = newString(maxAnagramLength);
        snprintf(formattedString, maxAnagramLength, "Anagram %zu: %s", i + 1, target[i]);
        strcpy(target[i], formattedString);
    }
}

size_t formatter(char * root, char * remainder, char ** target, size_t maxLength, size_t currentLength)
{   
    int index = find(remainder, "\" ");
    size_t difference = getStringDiff(remainder, root);
    if(index == -1)
    {
        snprintf(target[currentLength++], maxLength, "%s is an anagram of %s if %zu character%s removed", remainder, root, difference, difference == 1 ? " is" : "s are");
        return currentLength;
    }
    formatter(root, slice(remainder, 0, index), target, maxLength, currentLength);
    return formatter(root, slice(remainder, index + 1, strlen(remainder)), target, maxLength, currentLength + 1);
}

size_t formatWouldBeAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength)
{
    size_t length = 0;
    for (size_t i = 0; i < nAnagrams; i++)
    {
        int spaceIndex = find(target[i], "\" ");
        char * root = slice(target[i], 0, spaceIndex);
        char * remainder = slice(target[i], spaceIndex + 1, strlen(target[i]));
        length = formatter(root, remainder, target, maxAnagramLength, length);
    }
    return length;
}
