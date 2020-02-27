#include <string.h>
#include <stdlib.h>
#include "utils.h"

// Function to compare two strings alphabetically disregarding case and punctuation
bool compare(string str1, string str2) {
  string cleanedString1 = cleanString(str1), cleanedString2 = cleanString(str2);
  string cleanedLowerCaseString1 = toLowerCase(cleanedString1), cleanedLowerCaseString2 = toLowerCase(cleanedString2);
  bool str1LessThanStr2 = strncmp(cleanedString1, cleanedString2, strlen(str1)) < 0;
  free(cleanedString1);
  free(cleanedString2);
  free(cleanedLowerCaseString1);
  free(cleanedLowerCaseString2);
  return str1LessThanStr2;
}

// Function to swap two strings
void swap(string str1, string str2) {
    // Initialisation of tmp variables to store the strings during swap
    char tmp1[strlen(str1) + 1], tmp2[strlen(str2) + 1];

    // Swap operations
    strcpy(tmp1, str1);
    strcpy(tmp2, str2);
    strcpy(str1, tmp2);
    strcpy(str2, tmp1);
}

// Partition function for the qsort algorithm
size_t partition(string * strings, size_t left, size_t right) {
  // Sets the pivot to the last index in the subarray
  string pivot = strings[(left + right) / 2];
  // Sets i to the first index of the subarray to track how many elements have been sorted
  size_t i = left;

  /* For each element in the subarray, swap the first un-swapped element with the currently selected
  element if the compare function returns true */
  for (size_t j = left; j < right; j++) {
    if (compare(strings[j], pivot)) swap(strings[i++], strings[j]);
  }

  // Swap the first un-swapped element with the last element
  swap(strings[i], strings[right]);

  return i;
}

// Function to sort an array of strings alphabetically using quicksort
void sort(string * strings, int left, int right) {
  // Check that there is still a remaining subarray to be sorted
  if (left < right && right > 0) {
    // Sort a section of the array and return the pivot index to be used in the next calls
    size_t pivotIndex = partition(strings, left, right);
    // Sort the section of the array to the left of the pivot index
    sort(strings, left, (size_t)(pivotIndex - 1));
    // Sort the section of the array to the right of the pivot index
    sort(strings, (size_t)(pivotIndex + 1), right);
  }
}

