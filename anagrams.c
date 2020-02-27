#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"

/* Function to count the number of each letter in a string and store the count in a corresponding
array index */
size_t * countLetters(string str) {
  // Initialise a counter array of length 26 and set each value within it to 0
  size_t * counter = calloc(26, sizeof(size_t));
  // Iterate through each character in the string
  for (size_t i = 0; i < strlen(str); i++) {
    // If the character is alphabetical increment it's corresponding index in the array
    if ('a' <= str[i] && str[i] <= 'z') counter[str[i] - 'a']++;
    if ('A' <= str[i] && str[i] <= 'Z') counter[str[i] - 'A']++;
  }
  return counter;
}

// Function to generate counter array for each string
size_t ** generateMap(string * strings, size_t nLines, size_t cutoff) {
  // Allocate enough memory to the map to contain a counter array for each string
  size_t ** map = malloc(nLines * sizeof(size_t*));
  // Iterate over each string
  for (size_t i = 0; i < nLines; i++)
  {
    // Converts each string to one containing only alphabetical characters
    string cleanedString = cleanString(strings[i]);
    // Allocates enough memory to each index of the map to contain a single counter array
    map[i] = malloc(26 * sizeof(size_t));
    // Ignores all characters in the string past the cutoff point
    if (cutoff < strlen(cleanedString)) cleanedString[cutoff] = '\0';
    // Copies each countLetters array to its corresponding index in the map
    size_t * counter = countLetters(cleanedString);
    memcpy(map[i], counter, 26 * sizeof(size_t));
    free(cleanedString);
    free(counter);
  }

  return map;
}

/* Function to determine whether two strings are anagrams of each-other using their indices within
the generated map */
bool isAnagram(size_t a, size_t b, size_t ** map, string * strings)
{
  /* Preemptively eliminate strings that are not the same length when non-alphabetical characters
  have been removes */
  if(getStringDiff(strings[a], strings[b]) != 0) return false;
  // For each letter check that the same number of that letter exist in each string
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

/* Function to determine whether two strings would be anagrams of each-other if n characters was
removed from the end of one of them */
bool isMissingAnagram(size_t a, size_t b, size_t ** map, string * strings)
{
  /* Preemptively eliminate all strings of the same length as these have been dealt with in
  isAnagram() */
  if(getStringDiff(strings[a], strings[b]) == 0) return false;
  /* For each letter check that the same number of that letter exist in each string
  (this works despite the varying string lengths because of the cutoff the map ignores all
  characters over the length of string a) */
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

// Function to obtain the list of both anagrams and missingAnagrams
int ** getAnagrams(string * strings, bool (*compare)(size_t, size_t, size_t **, string * strings), size_t nLines, size_t longestLineLength)
{

  /* Initialise a 2D Integer array that stores a representation of each anagram match as a list
  of their indices in the input strings array */
  int ** matches = malloc(nLines * sizeof(int*));

  // Initialise a map to count the characters of each string
  size_t ** map = NULL;

  /* If the compare function is only checking for true anagrams only one map needs to be generated
  with effectively no cutoff */
  if (compare == isAnagram) map = generateMap(strings, nLines, longestLineLength);
  /* Initialise an array to keep track of which indices in the list of strings have been matched
  already to avoid double counting anagrams */
  size_t * matched = calloc(nLines, sizeof(size_t));

  // Initialise a counter for the number of anagrams found
  size_t nAnagrams = 0;
  // Iterate over each string
  for (size_t i = 0; i < nLines; i++)
  {
    // Allocate memory to each row of the matches array
    matches[i] = malloc(nLines * sizeof(int));
    // Check if the string in question has been matched before
    if(!(matched[i]))
    {
      /* If the function is looking for missingAnagrams a new map is needed for each string, with
      the cutoff being the length of said string */
      if (compare == isMissingAnagram) {
        string cleanedString = cleanString(strings[i]);
        map = generateMap(strings, nLines, strlen(cleanedString));
        free(cleanedString);
      }

      // Append the index of the root word to the start of the row
      matches[nAnagrams][0] = i;
      size_t anagramLength = 1;
      // Assume the string has no matching anagram
      bool foundMatch = false;
      /* Iterate over every other string including strings before the current one in the list
      as in this case of missingAnagrams each string can be part of more than one match */
      for (size_t j = 0; j < nLines; j++)
      {
        // Avoid comparing a string with itself and then check for a match
        if (j != i && compare(i, j, map, strings))
        {
          // Append each match to the row
          matches[nAnagrams][anagramLength++] = j;
          /* Set matched[j] to true to avoid recounting, set foundMatch to true
          so that the total string can be copied to the output */
          matched[j] = foundMatch = true;
        }
      }
      // Append -1 to the end of the row to indicate the formatter can stop parsing there
      if (foundMatch) matches[nAnagrams++][anagramLength] = -1;
      if (compare == isMissingAnagram) free(map);
    }
  }
  // Append -1 at the end of all the rows for the formatter to stop parsing
  matches[nAnagrams][0] = -1;

  // Deallocate memory
  if (compare == isAnagram) {
    for (size_t i = 0; i < nLines; i++) free(map[i]);
    free(map);
  }
  free(matched);

  // Return number of anagrams found
  return matches;
}

// Function to format the list of anagrams for printing to the output file
size_t formatAnagrams(string * strings, string * target, int ** matches, size_t maxLength) {
    // Initialise a counter to keep track of the number of anagrams generated
    size_t i;
    // Iterate over the matches array
    for (i = 0; matches[i][0] >= 0; i++) {
      // Append the root word to the beginning of the string
      snprintf(target[i], maxLength, "Anagram %zu: \"%s\"", i + 1, strings[matches[i][0]]);
      for (size_t j = 1; matches[i][j] >= 0; j++) {
        // Append every other word to the string
        snprintf(target[i], maxLength, "%s \"%s\"", target[i], strings[matches[i][j]]);
      }
    }
    // Return the count
    return i;
}

// Function to format the missingAnagrams for printing and return the number formatted
size_t formatMissingAnagrams(string * strings, string * target, int ** matches, size_t maxLength) {
    // Initialise a counter to keep track of the number of missingAnagrams generated
    size_t currentLength = 0;
    // Iterate over the matches array
    for (size_t i = 0; matches[i][0] >= 0; i++) {
      for (size_t j = 1; matches[i][j] >= 0; j++) {
        // Calculate the difference between the root word and each other string
        size_t difference = getStringDiff(strings[matches[i][j]], strings[matches[i][0]]);
        // Append each match to the list of strings
        /* This method works because root will always be the smallest string in the list as its
        map is the only one that the missingAnagrams are found in */
        snprintf(
          target[currentLength],
          maxLength,
          "Missing Anagram %zu: \"%s\" is an anagram of \"%s\" if %zu character%s removed",
          currentLength + 1, 
          strings[matches[i][0]],
          strings[matches[i][j]],
          difference,
          difference == 1 ? " is" : "s are"
        );
        currentLength++;
      }
    }
    return currentLength;
}
