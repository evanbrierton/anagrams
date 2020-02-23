#include <math.h>
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
    sort(strings, 0, (size_t)(nLines - 1));
    // Append sorted list of strings to the output file
    appendToOutput("output.txt", "The sorted list of words follows:");
    appendListToOutput("output.txt", nLines, strings);
    appendToOutput("output.txt", "");

    /* == Anagrams == */

    // Initialise anagrams to a string array of dimensions maxNAnagrams * maxAnagramLength
    char ** anagrams = newStringArray(maxNAnagrams, maxAnagramLength);
    // Feed generated anagrams into the anagrams array and return how many were generated
    size_t nAnagrams = getAnagrams(strings, anagrams, isAnagram, nLines, longestLineLength); 
    /* Formats the anagrams to be appended to the output and feeds the formatted anagrams back into
    the anagrams array */
    formatAnagrams(anagrams, nAnagrams, maxAnagramLength);
    // Appends the formatted list of anagrams to the output
    appendToOutput("output.txt", "Anagrams:");
    appendListToOutput("output.txt", nAnagrams, anagrams);
    appendToOutput("output.txt", "");

    /* == Would Be Anagrams == */

    // Initialise wouldBeAnagrams to a string array of dimensions maxNAnagrams * maxAnagramLength
    char ** wouldBeAnagrams = newStringArray(maxNAnagrams, maxAnagramLength);
    // Feed generated wouldBeAnagrams into the wouldBeAnagrams array and return how many were generated
    size_t nWouldBeAnagrams = getAnagrams(strings, wouldBeAnagrams, wouldBeAnagram, nLines, longestLineLength);
    /* Formats the anagrams to be appended to the output and feeds the formatted anagrams back into
    the anagrams array while returning th number of pairings */
    nWouldBeAnagrams = formatWouldBeAnagrams(wouldBeAnagrams, nWouldBeAnagrams, maxAnagramLength);
    // Appends the formatted list of wouldBeAnagrams to the output
    appendToOutput("output.txt", "Missing Anagrams:");
    appendListToOutput("output.txt", nWouldBeAnagrams, wouldBeAnagrams);

    return 0;
}
