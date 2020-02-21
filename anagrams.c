#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

size_t min(size_t a, size_t b) {
  return (a < b) ? a : b;
}

size_t * countLetters(char * str)
{
  size_t * counter = calloc(26, sizeof(size_t));
  for (size_t i = 0; i < strlen(str); i++)
  {
    if ('a' <= str[i] && str[i] <= 'z') counter[str[i] - 'a']++;
    if('A' <= str[i] && str[i] <='Z') counter[str[i] - 'A']++;
  }
  return counter;
}

size_t ** generateMap(char ** strings, size_t nLines, size_t cutoff)
{
  size_t ** map = malloc(nLines * sizeof(size_t*));
  for (size_t i = 0; i < nLines; i++)
  {
    char * cleanedString = cleanString(strings[i]);
    map[i] = malloc(26 * sizeof(size_t));
    if (cutoff < strlen(cleanedString)) cleanedString[cutoff] = '\0';
    memcpy(map[i], countLetters(cleanedString), 26 * sizeof(size_t));
  }

  return map;
}

bool isAnagram(size_t a, size_t b, size_t ** map, char ** strings)
{
  if(strlen(cleanString(strings[a])) != strlen(cleanString(strings[b]))) return false;
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

bool wouldBeAnagram(size_t a, size_t b, size_t ** map, char ** strings)
{
  if(strlen(cleanString(strings[a])) == strlen(cleanString(strings[b]))) return false;
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

size_t getAnagrams(char ** strings, char ** target, bool (*compare)(size_t, size_t, size_t **, char ** strings), size_t nLines, size_t longestLineLength)
{
  size_t ** map;
  if (compare == isAnagram) map = generateMap(strings, nLines, longestLineLength);
  size_t * matched = calloc(nLines, sizeof(size_t));

  size_t nAnagrams = 0;
  for (size_t i = 0; i < nLines; i++)
    if(!(matched[i]))
    {
      if (compare == wouldBeAnagram) map = generateMap(strings, nLines, strlen(cleanString(strings[i])));
      char * anagram = newString((nLines + 3) * longestLineLength);

      snprintf(anagram, (nLines + 3) * longestLineLength, "\"%s\"", strings[i]);
      bool foundMatch = false;
      for (size_t j = 0; j < nLines; j++)
      {
        if (j != i && compare(i, j, map, strings))
        {
          snprintf(anagram, (nLines + 3) * longestLineLength, "%s \"%s\"", anagram, strings[j]);
          matched[j] = foundMatch = true;
        }
      }
      if (foundMatch) strcpy(target[nAnagrams++], anagram);
    }

  return nAnagrams;
}

// size_t getAnagrams(char ** strings, char ** target, bool (*compare)(size_t, size_t, size_t **), size_t nLines, size_t longestLineLength)
// {
//   size_t * ignoreIndices = calloc(nLines, sizeof(size_t));
//   size_t ** map = generateMap(strings, nLines);
//   size_t anagramsLength = 0;
  
//   for (size_t i = 0; i < nLines + 1; i++)
//   {
//     if (!(ignoreIndices[i] && compare == isAnagram))
//     {
//     char ** matches = malloc(nLines * sizeof(char*));
//     for (size_t j = 0; j < nLines; j++) matches[j] = calloc(longestLineLength, sizeof(char));
    

//     strcpy(matches[0], strings[i]);
//     size_t matchesLength = 1;

//     for (size_t j = i + 1; j < nLines + 1; j++)
//     {
//       if (compare(i, j, map))
//       {
//         strcpy(matches[matchesLength++], strings[j]);
//         ignoreIndices[j] = true;
//       }
//     }
//     if (matchesLength > 1)
//     {
//       char * matchString = calloc((longestLineLength + 12 + nLines / 10) * nLines, sizeof(char));
//       for (size_t j = 0; j < matchesLength; j++)
//       {
//         strcat(matchString, "\"");
//         strcat(matchString, matches[j]);
//         strcat(matchString, "\" ");
//       }

//       strcpy(target[anagramsLength++], matchString);
//     }
//     }
//   }
//   return anagramsLength;
// }
