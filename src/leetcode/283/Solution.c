#include "Solution.h"

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, const int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            swap(nums + cnt, nums + i);
            cnt++;
        }
    }
}