// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "config.h"
// #include "sort.h"

// char * cleanString(char str[])
// {
//   char * clone = newString(strlen(str));
//   size_t currentLength = 0;
//   bool matched = false;
//   char charactersToRemove[] = "!’?;:,. ";
//   for (size_t i = 0; i < strlen(str); i++)
//   {
//     for (size_t j = 0; j < strlen(charactersToRemove); j++)
//       if (str[i] == charactersToRemove[j]) matched = true;

//     if (matched == false) clone[currentLength++] = str[i];
//     matched = false;
//   }
//   return clone;
// }

// void swapStrings(char * a, char * b)
// {
//     char temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int compareStrings(char a, char b)
// {
//   return a - b;
// }

// size_t partitionString(char str[], size_t left, size_t right)
// {
//   char pivot = str[right];
//   size_t i = left;

//   for (size_t j = left; j < right; j++)
//     if (compareStrings(str[j], pivot) < 0) swapStrings(&str[i++], &str[j]);
//       swapStrings(&str[i], &str[right]);
      
//   return i;
// }

// void sortString(char str[], size_t left, size_t right)
// {
//   if (left < right && right < LINE_LENGTH)
//   {
//     size_t p = partitionString(str, left, right);
//     sortString(str, left, p - 1);
//     sortString(str, p + 1, right);
//   }
// }

// void processStrings(char target[N_LINES][LINE_LENGTH], char strings[N_LINES][LINE_LENGTH])
// {
//   for (size_t i = 0; i < N_LINES; i++)
//   {
//     char * clone = toLowerCase(cleanString(strings[i]));
//     sortString(toLowerCase(cleanString(strings[i])), 0, strlen(clone) - 1);
//     strcpy(target[i], clone);
//   }
// }

// bool isAnagram(char processedStr1[], char processedStr2[])
// {
//   return strcmp(processedStr1, processedStr2) == 0;
// }

// // bool wouldBeAnagram(char )

// bool includes(size_t arr[], size_t length, size_t n)
// {
//   for (size_t i = 0; i < length; i++) if (arr[i] == n) return true;
//   return false;  
// }

// size_t getAnagrams(char strings[N_LINES][LINE_LENGTH], char target[N_LINES / 2][(LINE_LENGTH + 12 + N_LINES / 10) * N_LINES])
// {
//   char processedStrings[N_LINES][LINE_LENGTH];
//   processStrings(processedStrings, strings);

//   size_t ignoreIndices[N_LINES];
//   size_t ignoreIndicesLength = 0;
//   size_t anagramsLength = 0;

//   for (size_t i = 0; i < N_LINES; i++) printf("%s\n", processedStrings[i]);
  
  
//   for (size_t i = 0; i < N_LINES; i++)
//   {
//     if (includes(ignoreIndices, ignoreIndicesLength, i)) continue;

//     char matches[N_LINES][LINE_LENGTH] = {{0}};
//     strcpy(matches[0], strings[i]);
//     size_t matchesLength = 1;

//     for (size_t j = i + 1; j < N_LINES; j++)
//       if (isAnagram(processedStrings[i], processedStrings[j]))
//       {
//         strcpy(matches[matchesLength++], strings[j]);
//         ignoreIndices[ignoreIndicesLength++] = j;
//       }
//     if (matchesLength > 1)
//     {
//       char matchString[(LINE_LENGTH + 12 + N_LINES / 10) * N_LINES] = {0};
//       snprintf(matchString, sizeof matchString, "Anagram %zu:", anagramsLength + 1);
//       for (size_t j = 0; j < matchesLength; j++)
//       {
//         strcat(matchString, " \"");
//         strcat(matchString, matches[j]);
//         strcat(matchString, "\"");
//       }

//       strcpy(target[anagramsLength++], matchString);
//     }
//   }
//   return anagramsLength;
// }