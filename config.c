#include <stdio.h>

size_t getNLines(const char file[])
{
    FILE *fp;
    size_t lines = 1;

    fp = fopen(file, "r");
    for (int c = getc(fp); c != EOF; c = getc(fp)) if (c == '\n') lines++;
    return lines;
}

size_t getLongestLineLength(const char file[])
{
    FILE *fp;
    size_t length = 0;
    size_t max = 0;

    fp = fopen(file, "r");
    for (int c = getc(fp); c != EOF; c = getc(fp))
    {
        length++;
        if (c == '\n')
        {  
            if (length > max) max = length;
            length = 0;
        }
    };
    return max + 2;
}