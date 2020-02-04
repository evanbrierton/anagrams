#include <string.h>
#include <stdlib.h>
#include "config.h"

char * newString(size_t length)
{
  char * str = (char*)malloc(length + 1);
  return str;
}

void swap(char str1[], char str2[])
{
    char temp1[LINE_LENGTH] = {0}, temp2[LINE_LENGTH] = {0};

    strcpy(temp1, str1);
    strcpy(temp2, str2);
    strcpy(str1, temp2);
    strcpy(str2, temp1);
}

char * cloneString(char str[])
{
  char * clone = (char*)malloc(strlen(str) + 1);
  strcpy(clone, str);
  return clone;
}

void toLowerCase(char str[])
{ 
  for (size_t i = 0; i < strlen(str); i++)
    str[i] = ('A' <= str[i] && str[i] <= 'Z') ? str[i] + 'a' - 'A' : str[i];
}

int compare(char str1[], char str2[])
{
  /* Assignment of lowercase strings to variables so that memory allocated by malloc is released
  when the scope is exited */
  char * lowerCaseStr1 = cloneString(str1), * lowerCaseStr2 = cloneString(str2);
  toLowerCase(lowerCaseStr1);
  toLowerCase(lowerCaseStr2);
  return strcmp(lowerCaseStr1, lowerCaseStr2);
}

size_t partition(char strings[N_LINES][LINE_LENGTH], size_t left, size_t right)
{
  char * pivot = strings[right];
  size_t i = left;

  for (size_t j = left; j < right; j++)
    if (compare(strings[j], pivot) < 0) swap(strings[i++], strings[j]);
    
    swap(strings[i], strings[right]);
      
  return i;
}

void sort(char strings[N_LINES][LINE_LENGTH], size_t left, size_t right)
{
  if (left < right && right < N_LINES)
  {
    size_t p = partition(strings, left, right);
    sort(strings, left, p - 1);
    sort(strings, p + 1, right);
  }
}