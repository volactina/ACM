#include "Solution.h"

#define MAX_LST_NUM 1000
#define MAX_STR_LEN 31
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(const char **list1, const int list1Size,
                       const char **list2, const int list2Size, int *returnSize)
{
    char **ans = (char **)malloc(MAX_LST_NUM * sizeof(char *));
    *returnSize = 0;
    if (ans == NULL) {
        printf("error\n");
        return NULL;
    }
    for (int indexSum = 0; indexSum <= list1Size + list2Size - 2; indexSum++) {
        for (int i1 = 0; i1 <= indexSum; i1++) {
            int i2 = indexSum - i1;
            if (i1 >= list1Size || i2 >= list2Size) {
                continue;
            }
            if (strcmp(list1[i1], list2[i2]) != 0) {
                continue;
            }
            ans[*returnSize] = (char *)malloc(sizeof(char) * MAX_STR_LEN);
            strcpy(ans[*returnSize], list1[i1]);
            (*returnSize)++;
        }
        if (*returnSize) {
            break;
        }
    }
    return ans;
}