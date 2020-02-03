#include <stdio.h>
#include <string.h>
#include "config.h"

void getInput(const char input[], size_t linelength, char target[][linelength])
{
    FILE *fp;

    fp = fopen(input, "r");
    for (size_t i = 0; fgets(target[i], linelength, fp); i++) target[i][strlen(target[i]) - 1] = '\0';
    fclose(fp);
};
