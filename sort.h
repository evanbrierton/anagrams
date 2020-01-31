#include <stdio.h>
#include "config.h"

#ifndef SORT_H
#define SORT_H

void sortList(void* v, int size, int left, int right, int (*comp)(void*, void*));

#endif