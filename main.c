#include "config.h"
#include "io.h"
#include "sort.h"

int main(void)
{
    char data[N_LINES][LINE_LENGTH];
    getInput("input.txt", data);
    sort(data, 0, N_LINES - 1);
    for (size_t i = 0; i < N_LINES; i++) printf("%zu: %s\n", i, data[i]);

    return 0;
}
