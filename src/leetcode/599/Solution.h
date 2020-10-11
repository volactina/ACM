#ifndef __SOLUTION_H
#define __SOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(const char **list1, const int list1Size, const char **list2, const int list2Size, int *returnSize);

#endif