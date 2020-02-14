#include <math.h>
#include <stdlib.h>
#include "io.h"
#include "sort.h"
#include "anagrams.h"

int main(void)
{
    clearFile("output.txt");

    const size_t nLines = getNLines("input.txt");
    const size_t longestLineLength = getlongestLineLengthLength("input.txt");
    const size_t maxNAnagrams = nLines / 2;
    const size_t maxAnagramLength = (longestLineLength + 3) * nLines + 10 + floor(log10(nLines) + 1);

    char ** data = malloc(nLines * sizeof(char*));
    for (size_t i = 0; i < nLines; i++) data[i] = malloc(longestLineLength * sizeof(char));
    getInput("input.txt", data, longestLineLength);
    sort(data, 0, nLines - 1);
    
    appendToOutput("output.txt", "The sorted list of words follows:");
    appendListToOutput("output.txt", nLines, data);
    appendToOutput("output.txt", "");
    
    char ** anagrams = malloc(maxNAnagrams * sizeof(char*));
    for (size_t i = 0; i < nLines; i++) anagrams[i] = malloc(maxAnagramLength * sizeof(char));
    size_t nAnagrams = getAnagrams(data, anagrams, isAnagram);

    formatAnagrams(anagrams, nAnagrams, maxAnagramLength);
    
    appendListToOutput("output.txt", nAnagrams, anagrams);
    appendToOutput("output.txt", "");

    char ** wouldBeAnagrams = malloc(maxNAnagrams * sizeof(char*));
    for (size_t i = 0; i < nLines; i++) wouldBeAnagrams[i] = malloc(maxAnagramLength * sizeof(char));
    size_t nWouldBeAnagrams = getAnagrams(data, wouldBeAnagrams, wouldBeAnagram);

    formatWouldBeAnagrams(wouldBeAnagrams, nWouldBeAnagrams, maxAnagramLength);

    appendToOutput("output.txt", "Missing anagrams:");
    appendListToOutput("output.txt", nWouldBeAnagrams, wouldBeAnagrams);
    
    return 0;
}
