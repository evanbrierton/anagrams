#include <string.h>
#include <stdio.h>
#include <time.h>

#include <stdlib.h>
#include "config.h"

char toLowerCase(char c)
{
  return ('A' <= c && c <= 'Z') ? c = c + 'a' - 'A' : c;
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
    if (toLowerCase(*strings[j]) < toLowerCase(*pivot))
    {
      printf("%s, %s, %zu, %zu\n", strings[j], pivot, j, right);
      swap(strings[i], strings[j]);
      i++;
    }
  swap(strings[i], strings[right]);
  return i;
}

void sort(char strings[N_LINES][LINE_LENGTH], size_t left, size_t right)
{
  if (left < right) {
    size_t p = partition(strings, left, right);
    printf("p: %zu\n", p);
    sort(strings, left, p - 1);
    sort(strings, p + 1, right);
  }
}