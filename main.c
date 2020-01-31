#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "io.h"

int cmpstr(const void* v1, const void* v2)
{
    char *a1 = *(char**)v1;
    char *a2 = *(char**)v2;
    return strcmp(a1, a2);
}


int main(void)
{
    char data[N_LINES][LINE_LENGTH];
    getInput("input.txt", N_LINES, LINE_LENGTH, data);
    // sortList(data, sizeof(char*), 0, 8, (int (*)(void*, void*))(cmpstr));
    printf("%s\n", data[1]);
    return 0;
}
