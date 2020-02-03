#include <stdio.h>
#include <string.h>
#include "config.h"

void getInput(const char input[], char target[N_LINES][LINE_LENGTH])
{
    FILE *fp;

    fp = fopen(input, "r");
    for (size_t i = 0; fgets(target[i], LINE_LENGTH, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
};
