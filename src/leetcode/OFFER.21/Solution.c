#include "Solution.h"

static int cmp(const void *a, const void *b)
{
    int inta = *(int *)a;
    int intb = *(int *)b;
    if ((inta + intb) % 2) {
        return (inta % 2) ? -1 : 1;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(const int *nums, const int numsSize, int *returnSize)
{
    int *ans = NULL;
    *returnSize = numsSize;
    if (numsSize == 0) {
        return ans;
    }
    ans = (int *)malloc(sizeof(int) * numsSize);
    if (ans == NULL) {
        printf("error\n");
        return NULL;
    }
    memcpy(ans, nums, sizeof(int) * numsSize);
    qsort(ans, numsSize, sizeof(int), cmp);
    return ans;
}