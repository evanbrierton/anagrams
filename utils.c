#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils.h"
#include "io.h"

// Error handler
void error(bool condition, char * const message) {
  if (condition) {
    appendToOutput("error.txt", message);    // Print error message to output file
    fprintf(stderr, "Error: %s\n", message);  // Print error message to stderr
    exit(EXIT_FAILURE); // Terminate execution
  }
}

// Function to allocate memory for a new string based on an input length and return the string
char * newString(size_t length) {
  // Add 1 to the length to account for the null terminator and cast to char*
  char * str = calloc(length + 1, sizeof(char));
  return str;
}

// Function to allocate memory for a new string array
char ** newStringArray(size_t arrayLength, size_t stringLength) {
  // Allocate memory to the array itself
  char ** array = malloc(arrayLength * sizeof(char*));
  // Allocate enough memory for each string in the array
  for (size_t i = 0; i < arrayLength; i++) array[i] = newString(stringLength);
  return array;
}

// Function to remove certain characters from a string
char * removeCharacters(char * str, char * charactersToRemove) {
  // Initialise an array to store boolean values for every possible ASCII character
  bool characters[256] = {false};
  // Set the corresponding boolean character of the value to true if it is to be removed
  for (size_t i = 0; i < strlen(charactersToRemove); i++) characters[(size_t)charactersToRemove[i]] = true;

  // Initialise a new string so that the function is non-mutative
  char * cleanedString = newString(strlen(str));

  // Set the current length of the new string to 0
  size_t currentLength = 0;

  // Iterate over the char * and if the character is not to be removed, append it to the new string
  for (size_t i = 0; i < strlen(str); i++) {
    if (!characters[(size_t)str[i]]) cleanedString[currentLength++] = str[i];
  }

  return cleanedString;
}

// Function to remove non-alphabetical characters from a string
char * cleanString(char * str) {
  return removeCharacters(str, "   !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
}

// Function to convert a string to lower case
char * toLowerCase(char * str) {
  // Initialise a new string of the same length so that the function is non-mutative
  char * lowerCasedString = newString(strlen(str));
  // Replace all capital characters with their corresponding lowercase characters
  for (size_t i = 0; i < strlen(str); i++) {
    lowerCasedString[i] = (char)(('A' <= str[i] && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i]);
  }

  return lowerCasedString;
}

/* A function to return the difference in length between two strings, ignoring certain characters
defined in the cleanString function */
size_t getStringDiff(char * str1, char * str2) {
  char * cleanedString1 = cleanString(str1), * cleanedString2 = cleanString(str2);
  size_t difference = abs((int)strlen(cleanedString1) - (int)strlen(cleanedString2));
  free(cleanedString1);
  free(cleanedString2);
  return difference;
}
