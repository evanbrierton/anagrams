#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "utils.h"
#include "sort.h"

int min(int a, int b) {
  return (a < b) ? a : b;
}

void processStrings(char target[N_LINES][LINE_LENGTH], char strings[N_LINES][LINE_LENGTH])
{
  for (size_t i = 0; i < N_LINES; i++)
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

size_t getAnagrams(char strings[N_LINES][LINE_LENGTH], char target[N_LINES / 2][MAX_ANAGRAM_LENGTH], bool (*compare)(char *, char *))
{
  char processedStrings[N_LINES][LINE_LENGTH];
  processStrings(processedStrings, strings);

  size_t ignoreIndices[N_LINES] = {false};
  size_t anagramsLength = 0;

  // for (size_t i = 0; i < N_LINES; i++) printf("%s\n", processedStrings[i]);
  
  for (size_t i = 0; i < N_LINES; i++)
  {
    if (ignoreIndices[i] && compare == isAnagram) continue;

    char matches[N_LINES][LINE_LENGTH] = {{0}};
    strcpy(matches[0], strings[i]);
    size_t matchesLength = 1;

    for (size_t j = i + 1; j < N_LINES; j++)
      if (compare(strings[i], strings[j]))
      {
        strcpy(matches[matchesLength++], strings[j]);
        ignoreIndices[j] = true;
      }
    if (matchesLength > 1)
    {
      char matchString[(LINE_LENGTH + 12 + N_LINES / 10) * N_LINES] = {0};
      // snprintf(matchString, sizeof matchString, "Anagram %zu:", anagramsLength + 1);
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