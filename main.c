#include <math.h>
#include <stdlib.h>
#include "io.h"
#include "utils.h"
#include "sort.h"
#include "anagrams.h"

int main(void) {
    /* == Setup == */

    // Clear the output file
    clearFile("output.txt");
    // Get the number of lines in the input file
    const size_t nLines = getNLines("input.txt");
    // Get the length of the longest line in the input file
    const size_t longestLineLength = getLongestLineLengthLength("input.txt");
    /* Set the maximum number of anagrams to the number of lines divided by two as each anagram
    requires at least one pair */
    const size_t maxNAnagrams = nLines / 2;
    /* Set the maximum length of any given anagram to the longestLineLength + 3 to account for
    the longest possible individual string with quotation marks and a space, multiplied by nLines
    to account for the maximum number of strings in any given anagram, adding 10 for the prefix
    "Anagram:" and adding floor(log10(maxNAnagrams) + 1) to account for the number of digits in the
    prefixed number */
    const size_t maxAnagramLength = (longestLineLength + 3) * nLines + 10 + (size_t)floor(log10(maxNAnagrams) + 1);

    /* == Input and Sort == */

    // Initialise strings to a new string array of dimensions nLines * longestLineLength
    char ** strings = newStringArray(nLines, longestLineLength);
    // Feed the input from the text file into strings
    getInput("input.txt", strings, longestLineLength);
    // Sort strings alphabetically (case insensitive)
    sort(strings, 0, (size_t)(nLines - 1), toLowerCase);
    // Append sorted list of strings to the output file
    appendToOutput("output.txt", "The sorted list of words follows:");
    appendListToOutput("output.txt", nLines, strings);
    appendToOutput("output.txt", "");

    /* == Anagrams == */

    /* Get a 2D integer array with each row containing the indices of the strings that have matched
    with each-other */
    int ** matches = getAnagrams(strings, isAnagram, nLines, longestLineLength);
    // Initialise anagrams to a string array of dimensions maxNAnagrams * maxAnagramLength
    char ** anagrams = newStringArray(maxNAnagrams, maxAnagramLength);
    /* Formats the anagrams to be appended to the output and feeds the formatted anagrams back into
    the anagrams array */
    size_t nAnagrams = formatAnagrams(strings, anagrams, matches, maxAnagramLength);
    // Appends the formatted list of anagrams to the output
    appendToOutput("output.txt", "Anagrams:");
    appendListToOutput("output.txt", nAnagrams, anagrams);
    appendToOutput("output.txt", "");

    /* == Would Be Anagrams == */

    /* Get a 2D integer array with each row containing the indices of the strings that have matched
    with each-other given the constraints */
    int ** wouldBeMatches = getAnagrams(strings, missingAnagram, nLines, longestLineLength);
    // Initialise missingAnagrams to a string array of dimensions maxNAnagrams * maxAnagramLength
    char ** missingAnagrams = newStringArray(maxNAnagrams, maxAnagramLength);
    /* Formats the anagrams to be appended to the output and feeds the formatted anagrams back into
    the anagrams array while returning th number of pairings */
    size_t nMissingAnagrams = formatMissingAnagrams(strings, missingAnagrams, wouldBeMatches, maxAnagramLength);
    // Appends the formatted list of missingAnagrams to the output
    appendToOutput("output.txt", "Missing Anagrams:");
    appendListToOutput("output.txt", nMissingAnagrams, missingAnagrams);
    
    // Deallocate memory
    for (size_t i = 0; i < nLines; i++) free(strings[i]);
    free(strings);
    

    return 0;
}
