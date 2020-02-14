#include "config.h"
#include "io.h"
#include "sort.h"
#include "anagrams.h"
#include "utils.h"
#include <string.h>

int main(void)
{
    clearFile("output.txt");

    char data[N_LINES][LINE_LENGTH];
    getInput("input.txt", data);
    sort(data, 0, N_LINES - 1);
    for (size_t i = 0; i < N_LINES; i++) printf("%zu: %s\n", i, data[i]);
    
    appendToOutput("output.txt", "The sorted list of words follows:");
    appendListToOutput("output.txt", N_LINES, LINE_LENGTH, data);
    appendToOutput("output.txt", "");
    
    char anagrams[MAX_N_ANAGRAMS][MAX_ANAGRAM_LENGTH];
    size_t nAnagrams = getAnagrams(data, anagrams, isAnagram);

    formatAnagrams(anagrams, nAnagrams);
    
    appendListToOutput("output.txt", nAnagrams, MAX_ANAGRAM_LENGTH, anagrams);
    appendToOutput("output.txt", "");

    char wouldBeAnagrams[MAX_N_ANAGRAMS][MAX_ANAGRAM_LENGTH];
    size_t nWouldBeAnagrams = getAnagrams(data, wouldBeAnagrams, wouldBeAnagram);

    formatWouldBeAnagrams(wouldBeAnagrams, nWouldBeAnagrams);

    appendListToOutput("output.txt", nWouldBeAnagrams, MAX_ANAGRAM_LENGTH, wouldBeAnagrams);
    
    return 0;
}
