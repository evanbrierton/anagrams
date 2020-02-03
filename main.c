#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "io.h"
#include "sort.h"

int main(void)
{
    char data[N_LINES][LINE_LENGTH];
    // const char* arr[] = { "geeksforgeeks", "geeksquiz", "clanguage" }; 
    getInput("input.txt", LINE_LENGTH, data);
    // sort(data);
    sort(data, 0, 13);
    for (size_t i = 0; i < N_LINES; i++) printf("%zu: %s\n", i, data[i]);
    // for (size_t i = 0; i < strlen(data[10]) + 2; i++) printf("\"%c\"\n", data[10][i]);

    

    return 0;
}
