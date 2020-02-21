#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "io.h"

// Error handler
void error(bool condition, const char * message)
{
  if (condition)
  {
    appendToOutput("output.txt", message);    // Print error message to output file
    fprintf(stderr, "Error: %s\n", message);  // Print error message to stderr
    exit(EXIT_FAILURE); // Terminate execution
  }
}

// Function to allocate memory to a new string based on an input length and return the string
char * newString(size_t length)
{
  // Add 1 to the length to account for the null terminator and cast to char*
  char * str = (char*)malloc((length + 1) * sizeof(char));
  return str;
}

char ** newStringArray(size_t arrayLength, size_t stringLength)
{
  char ** array = malloc(arrayLength * sizeof(char*));
  for (size_t i = 0; i < arrayLength; i++) array[i] = newString(stringLength);
  return array;
}

int find(char * str, const char * substr)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        bool match = true;
        for (size_t j = 0; j < strlen(substr); j++)
        {
           if (str[i + j] != substr[j])
           {
               match = false;
               break;
           }
        }
        if (match == true) return i + strlen(substr) - 1;
    }
    return -1;
}

// Function to slice out a section of a string and return the slice
char * slice(const char * str, size_t a, size_t b)
{
  // Initialise a new string of the length of the slice
  char * slicedString = newString(b - a);
  // Set each character in the sliced string
  for (size_t i = 0; i < b - a; i++) slicedString[i] = str[i + a];
  // Append the null terminator
  slicedString[b - a] = '\0';
  return slicedString;
}

// Function to convert a clone of a string to lower case and return that clone
char * toLowerCase(char str[])
{ 
  // Initialise a new string of the same length
  char * lowerCaseStr = newString(strlen(str));
  // Replace all capital characters with their corresponding lowercase characters
  for (size_t i = 0; i < strlen(str); i++)
    lowerCaseStr[i] = (char)(('A' <= str[i] && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i]);

  return lowerCaseStr;
}

char * removeCharacters(char str[], const char charactersToRemove[])
{
  char * clone = newString(strlen(str));
  size_t currentLength = 0;
  bool matched = false;
  for (size_t i = 0; i < strlen(str); i++)
  {
    for (size_t j = 0; j < strlen(charactersToRemove); j++)
      if (str[i] == charactersToRemove[j]) matched = true;

    if (matched == false) clone[currentLength++] = str[i];
    matched = false;
  }
  
  return clone;
}

// char * removeCharacters(char str[], const char charactersToRemove[])
// {
//   bool characters[256];
//   for (size_t i = 0; i < strlen(charactersToRemove); i++) characters[(size_t)charactersToRemove[i]] = true;

//   char * clone = newString(strlen(str));

//   size_t currentLength = 0;

//   for (size_t i = 0; i < strlen(str); i++)
//   {
//     if (!characters[(size_t)str[i]]) clone[currentLength++] = str[i];
//   }
//   return clone;
// }

char * cleanString(char str[])
{
  return toLowerCase(removeCharacters(str, "!’?;:,. "));
}

size_t getStringDiff(char * str1, char * str2)
{
  return abs((int)strlen(cleanString(str1)) - (int)strlen(cleanString(str2)));
}


void swapChars(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int compareChars(char a, char b)
{
  return a - b;
}

size_t partitionString(char str[], size_t left, size_t right)
{
  char pivot = str[right];
  size_t i = left;

  for (size_t j = left; j < right; j++)
    if (compareChars(str[j], pivot) < 0) swapChars(&str[i++], &str[j]);
      swapChars(&str[i], &str[right]);
      
  return i;
}

void sortString(char str[], size_t left, size_t right)
{
  if (left < right && right < strlen(str))
  {
    size_t p = partitionString(str, left, right);
    sortString(str, left, p - 1);
    sortString(str, p + 1, right);
  }
}
