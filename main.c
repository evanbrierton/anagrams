#include "config.h"
#include "io.h"
#include "sort.h"
#include "anagrams.h"

int main(void)
{
    char data[N_LINES][LINE_LENGTH];
    getInput("input.txt", data);
    sort(data, 0, N_LINES - 1);
    for (size_t i = 0; i < N_LINES; i++) printf("%zu: %s\n", i, data[i]);

    clearFile("output.txt");
    appendToOutput("output.txt", "The sorted list of words follows:");
    appendListToOutput("output.txt", N_LINES, LINE_LENGTH, data);
    appendToOutput("output.txt", "");
    
    const size_t maxNAnagrams = N_LINES / 2;
    const size_t maxAnagramLength = (LINE_LENGTH + 12 + N_LINES / 10) * N_LINES;
    char anagrams[maxNAnagrams][maxAnagramLength];
    size_t nAnagrams = getAnagrams(data, anagrams);

    appendListToOutput("output.txt", nAnagrams, maxAnagramLength, anagrams);
    
    return 0;
}
