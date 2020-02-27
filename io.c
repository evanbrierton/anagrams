#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "utils.h"

// Function to clear all text from a file
void clearFile(const string file) {
    /* Initialise fp to a pointer to the file to be wiped, opening with the "w" flag also clears
    the file */
    FILE * fp = fopen(file, "w");
    // Check if file has been found and cleared successfully
    error(!fp, strerror(errno));

    // Close file
    fclose(fp);
}

// Function to calculate the number of lines in an input file
size_t getNLines(const string file) {
    // Initialise variable to track the number of lines in the file
    size_t lines = 0;

    // Initialise fp to the input file in read mode
    FILE * fp = fopen(file, "r");
    // Check if the file has been found
    error(!fp, strerror(errno));

    // Initialise variable to track the last character in the file aside from EOF
    char lastCharacter = 0;
    // Iterate over each character in the file
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        lastCharacter = (char)c;
        // Increment lines if a newline character is encountered
        if (c == '\n') lines++;
    }
    // Check if last character is a newline
    error(lastCharacter != '\n', "Last character must be a newline");\

    // Close the file
    fclose(fp);
    return lines;
}

// Function to return the length of the longest line in the input file
size_t getLongestLineLengthLength(const string file) {
    /* Initialise variables to track the length of the current line being read and the maximum
    length read so far; */
    size_t length = 0, max = 0;

    // Initialise fp to a pointer to the file in read mode
    FILE * fp = fopen(file, "r");
    // Check that the file has been found
    error(!fp, strerror(errno));

    // Iterate over each character in the file
    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        // Increment length for each character in the line
        length++;
        if (c == '\n') {
            // At a newline set the max to the current length if it is the longest found
            if (length > max) max = length;
            // Reset the current line length to 0
            length = 0;
        }
    };
    // Return max + 1 to account for the inclusion of the null terminator
    return max + 1;
}

// Function to read input from a text file and output each line to a string array
void getInput(const string input, string * target, size_t lineLength) {
    // Initialise fp to a pointer to the input file
    FILE * fp = fopen(input, "r");
    // Check if  file has been found
    error(!fp, strerror(errno));

    /* For each line in the input feed the line into its corresponding index in the target string
    array and replace the newline character with the null terminator */
    for (size_t i = 0; fgets(target[i], lineLength, fp); i++) target[i][strlen(target[i]) - 1] = '\0';

    // Close file
    fclose(fp);
}

// Function to append a line of text to the output file
void appendToOutput(const string output, const string string) {
    // Initialise fp to a pointer to the output file in append mode
    FILE * fp = fopen(output, "a");
    // Check if file has been found
    error(!fp, strerror(errno));

    // Append line of text to the input file
    fprintf(fp, "%s\n", string);

    // Close file
    fclose(fp);
}

// Function to append an array of strings to the output file
void appendListToOutput(const string output, size_t lines, string * strings) {
    // For each string in the array call appendToOutput on the string
    for (size_t i = 0; i < lines; i++) appendToOutput(output, strings[i]);
}
