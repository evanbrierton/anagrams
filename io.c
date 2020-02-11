#include <stdio.h>
#include <string.h>
#include "config.h"

void getInput(const char input[], char target[][LINE_LENGTH])
{
    FILE *fp;

    fp = fopen(input, "r");
    for (size_t i = 0; fgets(target[i], LINE_LENGTH, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
};

void clearFile(const char file[])
{
    FILE *fp;

    fp = fopen(file, "w");
    fclose(fp);
}

void appendToOutput(const char output[], const char string[])
{
    FILE *fp;

    fp = fopen(output, "a");
    fprintf(fp, "%s\n", string);
    fclose(fp);
}

void appendListToOutput(const char output[], size_t lines, size_t linelength, char strings[][linelength])
{
    for (size_t i = 0; i < lines; i++) appendToOutput(output, strings[i]);
}
