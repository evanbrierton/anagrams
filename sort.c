#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"


char * toLowerCase(char str[])
{ 
  char * lowerCaseStr = (char*)malloc(LINE_LENGTH + 1);
  for (size_t i = 0; i < strlen(str); i++)
    lowerCaseStr[i] = ('A' <= str[i] && str[i] <= 'Z') ? str[i] + 'a' - 'A' : str[i];
  return lowerCaseStr;
}

void swap(char str1[], char str2[])
{

    char temp1[LINE_LENGTH] = {0}, temp2[LINE_LENGTH] = {0};

    strcpy(temp1, str1);
    strcpy(temp2, str2);
    strcpy(str1, temp2);
    strcpy(str2, temp1);
}

size_t partition(char strings[N_LINES][LINE_LENGTH], size_t left, size_t right)
{
  char * pivot = strings[right];
  size_t i = left;
  for (size_t j = left; j < right; j++)
  {
    char * str1 = toLowerCase(strings[j]), * str2 = toLowerCase(pivot);
    if (strcmp(str1, str2) < 0)
    {
      swap(strings[i], strings[j]);
      i++;
    }
  }
  swap(strings[i], strings[right]);
  return i;
}

void sort(char strings[N_LINES][LINE_LENGTH], size_t left, size_t right)
{
  if (left < right && right < N_LINES) {
    size_t p = partition(strings, left, right);
    printf("\np=%zu\n\n", p);
    sort(strings, left, p - 1);
    sort(strings, p + 1, right);
  }
}