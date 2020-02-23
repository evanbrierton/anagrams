#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"

/* unction to count the number of each letter in a string and store the count in a corresponding
array index */
size_t * countLetters(char * str) {
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
size_t ** generateMap(char ** strings, size_t nLines, size_t cutoff) {
  // Allocate enough memory to the map to contain a counter array for each string
  size_t ** map = malloc(nLines * sizeof(size_t*));
  // Iterate over each string
  for (size_t i = 0; i < nLines; i++)
  {
    // Converts each string to one containing only alphabetical characters
    char * cleanedString = cleanString(strings[i]);
    // Allocates enough memory to each index of the map to contain a single counter array
    map[i] = malloc(26 * sizeof(size_t));
    // Ignores all characters in the string past the cutoff point
    if (cutoff < strlen(cleanedString)) cleanedString[cutoff] = '\0';
    // Copies each countLetters array to its corresponding index in the map
    memcpy(map[i], countLetters(cleanedString), 26 * sizeof(size_t));
  }

  return map;
}

/* Function to determine whether two strings are anagrams of each-other using their indices within
the generated map */
bool isAnagram(size_t a, size_t b, size_t ** map, char ** strings)
{
  /* Preemptively eliminate strings that are not the same length when non-alphabetical characters
  have been removes */
  if(strlen(cleanString(strings[a])) != strlen(cleanString(strings[b]))) return false;
  // For each letter check that the same number of that letter exist in each string
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

/* Function to determine whether two strings would be anagrams of each-other if n characters was
removed from the end of one of them */
bool wouldBeAnagram(size_t a, size_t b, size_t ** map, char ** strings)
{
  /* Preemptively eliminate all strings of the same length as these have been dealt with in
  isAnagram() */
  if(strlen(cleanString(strings[a])) == strlen(cleanString(strings[b]))) return false;
  /* For each letter check that the same number of that letter exist in each string
  (this works despite the varying string lengths because of the cutoff the map ignores all
  characters over the length of string a) */
  for (size_t i = 0; i < 26; i++) if(map[a][i] != map[b][i]) return false;
  return true;
}

// Function to obtain the list of both anagrams and wouldBeAnagrams
size_t getAnagrams(char ** strings, char ** target, bool (*compare)(size_t, size_t, size_t **, char ** strings), size_t nLines, size_t longestLineLength)
{
  // Values to use for array initialisations, these values are explained in main.c
  const size_t maxNAnagrams = nLines / 2;
  const size_t maxAnagramLength = (longestLineLength + 3) * nLines + 10 + (size_t)floor(log10(maxNAnagrams) + 1);

  // Initialise a map to count the characters of each string
  size_t ** map;
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
    // Check if the string in question has been matched before
    if(!(matched[i]))
    {
      /* If the function is looking for wouldBeAnagrams a new map is needed for each string, with the
      cutoff being the length of said string */
      if (compare == wouldBeAnagram) map = generateMap(strings, nLines, strlen(cleanString(strings[i])));

      // Initialise a string to store the anagram
      char * anagram = newString(maxAnagramLength);

      // Append the root word to the beginning of the anagram string
      snprintf(anagram, maxAnagramLength, "\"%s\"", strings[i]);
      // Assume the string has no matching anagram
      bool foundMatch = false;
      /* Iterate over every other string including strings before the current one in the list
      as in this case of wouldBeAnagrams each string can be part of more than one match */ 
      for (size_t j = 0; j < nLines; j++)
      {
        // Avoid comparing a string with itself and then check for a match
        if (j != i && compare(i, j, map, strings))
        {
          // Append the match to the output string
          snprintf(anagram, maxAnagramLength, "%s \"%s\"", anagram, strings[j]);
          /* Set matched[j] to true to avoid recounting, set foundMatch to true
          so that the total string can be copied to the output */
          matched[j] = foundMatch = true;
        }
      }
      // Copy string to output
      if (foundMatch) strcpy(target[nAnagrams++], anagram);
    }
  // Return number of anagrams found
  return nAnagrams;
}

// Function to format the list of anagrams for printing to the output file
void formatAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength) {
    // Iterate over each anagram
    for (size_t i = 0; i < nAnagrams; i++) {
        /* For each anagram in the list append the prefix "Anagram n:" where n is it's position in the
        list and feed it to it's corresponding index in the target array */
        char * formattedString = newString(maxAnagramLength);
        snprintf(formattedString, maxAnagramLength, "Anagram %zu: %s", i + 1, target[i]);
        strcpy(target[i], formattedString);
    }
}

/* Recursive partition function to aid formatting the wouldBeAnagrams and returning the number of
lines in the formatted list */
size_t formatterPartition(char * root, char * remainder, char ** target, size_t maxLength, size_t currentLength) {   
    // Finds the index of any space immediately preceded by a quotation mark in the string
    int index = find(remainder, "\" ");
    /* Gets the difference between the root string of the wouldBeAnagram and the total length of
    the remaining strings */
    size_t difference = getStringDiff(remainder, root);
    // find() returns -1 if no index is found meaning there is only one string left in the remainder
    if(index == -1) {
        // Append each string to the target array
        snprintf(target[currentLength], maxLength, "Missing Anagram %zu: %s is an anagram of %s if %zu character%s removed", currentLength + 1, remainder, root, difference, difference == 1 ? " is" : "s are");
        // return the length
        return currentLength + 1;
    }
    /* If there is more than one string in the remainder partition it at the first space character
    and run the function again on each partition returning the greater index */
    formatterPartition(root, slice(remainder, 0, index), target, maxLength, currentLength);
    return formatterPartition(root, slice(remainder, index + 1, strlen(remainder)), target, maxLength, currentLength + 1);
}

// Function to format the wouldBeAnagrams for printing and return the number formatted
size_t formatWouldBeAnagrams(char ** target, size_t nAnagrams, size_t maxAnagramLength) {
    // Initialise the length of the list of formatted wouldBeAnagrams to 0
    size_t length = 0;
    // Iterate through each one of the found wouldBeAnagrams
    for (size_t i = 0; i < nAnagrams; i++) {
        // Find the index of the first space character immediately preceded by a quotation mark
        int spaceIndex = find(target[i], "\" ");
        /* The root will always be the smallest string in the list because its map is the only one
        that the wouldBeAnagrams are found in */
        char * root = slice(target[i], 0, spaceIndex);
        // The remainder wil be the rest of the strings excluding the smallest string
        char * remainder = slice(target[i], spaceIndex + 1, strlen(target[i]));
        /* The remainder is then recursively broken down into its constituent strings and each
        string is matched to the root for printing */
        length = formatterPartition(root, remainder, target, maxAnagramLength, length);
    }
    return length;
}

