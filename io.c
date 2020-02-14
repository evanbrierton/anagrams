#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void getInput(const char * input, char ** target, size_t lineLength)
{
    FILE *fp;

    fp = fopen(input, "r");
    for (size_t i = 0; fgets(target[i], lineLength, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
};

void clearFile(const char * file)
{
    FILE *fp;

    fp = fopen(file, "w");
    fclose(fp);
}

void appendToOutput(const char * output, const char * string)
{
    FILE *fp;

    fp = fopen(output, "a");
    fprintf(fp, "%s\n", string);
    fclose(fp);
}

void appendListToOutput(const char * output, size_t lines, char ** strings)
{
    for (size_t i = 0; i < lines; i++) appendToOutput(output, strings[i]);
}

size_t getNLines(const char file[])
{
    FILE *fp;
    size_t lines = 1;

    fp = fopen(file, "r");
    char lastCharacter;
    for (int c = getc(fp); c != EOF; c = getc(fp))
    {
        lastCharacter = c;
        if (c == '\n') lines++;
    }
    if (lastCharacter != '\n')
    {
        const char * error = "Error: Last character in the input file must be a newline";
        printf("%s\n", error);
        appendToOutput("output.txt", error);
        exit(1);
    }
    
    return lines - 1;
}

size_t getlongestLineLengthLength(const char file[])
{
    FILE *fp;
    size_t length = 0;
    size_t max = 0;

    fp = fopen(file, "r");
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

void formatWouldBeAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength)
{
     for (size_t i = 0; i < nAnagrams; i++)
    {
        char * formattedString = newString(maxAnagramLength);
        size_t spaceIndex = 0;
        for (size_t j = 0; j < strlen(target[i]); j++)
            if (target[i][j] == ' ' && target[i][j - 1] == '"')
            {
                spaceIndex = j;
                break;
            }
        char * str1 = slice(target[i], 0, spaceIndex);
        char * str2 = slice(target[i], spaceIndex + 1, strlen(target[i]) - 1);
        char * shortest = getShortestString(str1, str2, "!’?;:,. ");
        char * longest = getLongestString(str1, str2, "!’?;:,. ");
        size_t difference = strlen(cleanString(longest)) - strlen(cleanString(shortest));
        snprintf(formattedString, maxAnagramLength, "%s is an anagram of %s if %zu character%s removed", longest, shortest, difference, difference == 1 ? " is" : "s are");
        strcpy(target[i], formattedString);
    }
}