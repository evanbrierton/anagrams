#include <stdio.h>
#include <string.h>
#include "config.h"
#include "utils.h"

void getInput(const char input[], char target[N_LINES][LINE_LENGTH])
{
    FILE *fp;

    fp = fopen(input, "r");
    for (size_t i = 0; fgets(target[i], LINE_LENGTH, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
};

void clearFile(const char file[])
{
    FILE *fp;

    fp = fopen(file, "w");
    fclose(fp);
}

void appendToOutput(const char output[], const char string[])
{
    FILE *fp;

    fp = fopen(output, "a");
    fprintf(fp, "%s\n", string);
    fclose(fp);
}

void appendListToOutput(const char output[], size_t lines, size_t linelength, char strings[lines][linelength])
{
    for (size_t i = 0; i < lines; i++) appendToOutput(output, strings[i]);
}

void formatAnagrams(char target[MAX_N_ANAGRAMS][MAX_ANAGRAM_LENGTH], size_t nAnagrams)
{
    for (size_t i = 0; i < nAnagrams; i++) {
        char * formattedString = newString(MAX_ANAGRAM_LENGTH);
        snprintf(formattedString, MAX_ANAGRAM_LENGTH, "Anagram %zu: %s", i + 1, target[i]);
        strcpy(target[i], formattedString);
    }
}

void formatWouldBeAnagrams(char target[MAX_N_ANAGRAMS][MAX_ANAGRAM_LENGTH], size_t nAnagrams)
{
     for (size_t i = 0; i < nAnagrams; i++)
    {
        char * formattedString = newString(MAX_ANAGRAM_LENGTH);
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
        snprintf(formattedString, MAX_ANAGRAM_LENGTH, "%s is an anagram of %s if %zu character%s removed", longest, shortest, difference, difference == 1 ? " is" : "s are");
        strcpy(target[i], formattedString);
    }
}