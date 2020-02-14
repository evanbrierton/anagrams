#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

int min(int a, int b) {
  return (a < b) ? a : b;
}

void processStrings(char ** target, char ** strings, size_t nLines)
{
  for (size_t i = 0; i < nLines; i++)
  {
    char * clone = cleanString(strings[i]);
    sortString(clone, 0, strlen(clone) - 1);
    strcpy(target[i], clone);
  }
}

bool isAnagram(char str1[], char str2[])
{
  char * clone1 = cleanString(str1);
  char * clone2 = cleanString(str2);
  if (strlen(clone1) != strlen(clone2)) return false;
  sortString(clone1, 0, strlen(clone1) - 1);
  sortString(clone2, 0, strlen(clone2) - 1);
  return strcmp(clone1, clone2) == 0;
}

bool wouldBeAnagram(char str1[], char str2[])
{
  char * clone1 = cleanString(str1);
  char * clone2 = cleanString(str2);
  if  (strlen(clone1) == strlen(clone2)) return false;
  int length = min(strlen(clone1), strlen(clone2));
  clone1[length] = '\0';
  clone2[length] = '\0';
  sortString(clone1, 0, strlen(clone1) - 1);
  sortString(clone2, 0, strlen(clone2) - 1);
  return strcmp(clone1, clone2) == 0;
}

size_t getAnagrams(char ** strings, char ** target, bool (*compare)(char *, char *), size_t nLines, size_t longestLineLength)
{
  // char processedStrings[nLines][longestLineLength];
  // processStrings(processedStrings, strings);

  size_t * ignoreIndices = calloc(nLines, sizeof(size_t));
  
  size_t anagramsLength = 0;

  // for (size_t i = 0; i < nLines; i++) printf("%s\n", processedStrings[i]);
  
  for (size_t i = 0; i < nLines + 1; i++)
  {
    if (ignoreIndices[i] && compare == isAnagram) continue;

    char ** matches = malloc(nLines * sizeof(char*));
    for (size_t j = 0; j < nLines; j++) matches[j] = calloc(longestLineLength, sizeof(char));
    

    strcpy(matches[0], strings[i]);
    size_t matchesLength = 1;

    for (size_t j = i + 1; j < nLines + 1; j++)
      if (compare(strings[i], strings[j]))
      {
        strcpy(matches[matchesLength++], strings[j]);
        ignoreIndices[j] = true;
      }
    if (matchesLength > 1)
    {
      char * matchString = calloc((longestLineLength + 12 + nLines / 10) * nLines, sizeof(char));
      for (size_t j = 0; j < matchesLength; j++)
      {
        strcat(matchString, "\"");
        strcat(matchString, matches[j]);
        strcat(matchString, "\" ");
      }

      strcpy(target[anagramsLength++], matchString);
    }
  }
  return anagramsLength;
}