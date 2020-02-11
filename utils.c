#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

char * newString(size_t length)
{
  char * str = (char*)malloc(length + 1);
  return str;
}

char * cloneString(char str[])
{
  char * clone = newString(strlen(str));
  return strcpy(clone, str);
}

char * toLowerCase(char str[])
{ 
  char * lowerCaseStr = newString(strlen(str));
  for (size_t i = 0; i < strlen(str); i++)
    lowerCaseStr[i] = ('A' <= str[i] && str[i] <= 'Z') ? str[i] + 'a' - 'A' : str[i];
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

char * cleanString(char str[])
{
  return toLowerCase(removeCharacters(str, "!’?;:,. "));
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
  if (left < right && right < LINE_LENGTH)
  {
    size_t p = partitionString(str, left, right);
    sortString(str, left, p - 1);
    sortString(str, p + 1, right);
  }
}