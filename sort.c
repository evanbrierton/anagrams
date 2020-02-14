#include <string.h>
#include <stdbool.h>
#include "utils.h"

void swap(char * str1, char * str2)
{
    char temp1[strlen(str1) + 1], temp2[strlen(str2) + 1];

    strcpy(temp1, str1);
    strcpy(temp2, str2);
    strcpy(str1, temp2);
    strcpy(str2, temp1);
}

bool compare(char * str1, char * str2)
{
  /* Assignment of lowercase strings to variables so that memory allocated by malloc is released
  when the scope is exited */
  char * lowerCaseStr1 = toLowerCase(str1), * lowerCaseStr2 = toLowerCase(str2);
  return strcmp(lowerCaseStr1, lowerCaseStr2) < 0;
}

size_t partition(char ** strings, size_t left, size_t right)
{
  char * pivot = strings[right];
  size_t i = left;

  for (size_t j = left; j < right; j++)
    if (compare(strings[j], pivot)) swap(strings[i++], strings[j]);
    
    swap(strings[i], strings[right]);
      
  return i;
}

void sort(char ** strings, int left, int right)
{
  if (left < right && right > 0)
  {
    size_t p = partition(strings, left, right);
    sort(strings, left, p - 1);
    sort(strings, p + 1, right);
  }
}