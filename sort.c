#include <string.h>
#include "utils.h"

// Function to compare two strings alphabetically disregarding case and punctuation
bool compare(char * str1, char * str2) {
  return strcmp(toLowerCase(cleanString(str1)), toLowerCase(cleanString(str2))) < 0;
}

// Function to swap two strings
void swap(char * str1, char * str2) {
    // Initialisation of tmp variables to store the strings during swap
    char tmp1[strlen(str1) + 1], tmp2[strlen(str2) + 1];

    // Swap operations
    strcpy(tmp1, str1);
    strcpy(tmp2, str2);
    strcpy(str1, tmp2);
    strcpy(str2, tmp1);
}

// Partition function for the qsort algorithm
size_t partition(char ** strings, size_t left, size_t right) {
  // Sets the pivot to the last index in the subarray
  char * pivot = strings[right];
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
void sort(char ** strings, int left, int right) {
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
