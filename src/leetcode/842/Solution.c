#include "Solution.h"

/* 
枚举(i,j)，其中i<j<length,对于每一个(i,j)，取0..i为序列中的第一个数字,i+1..j为序列中的第二个数字，验证后续序列是否满足条件
枚举的时间复杂度O(length^2)，对于每一次枚举检查后续序列是否满足条件的时间复杂度应是线性的
所以总的时间复杂度是O(length^3)
*/
#define DEBUG true
#define DEBUGPRINT(x) if (DEBUG) {x;}

/* 将字符串S中[start,end]位转为数字 */
bool RetrieveOneNum(char *S, int start, int end, int *num)
{
    char *SS = (char*)malloc(end - start + 2);
    strncpy(SS, S + start, end - start + 1);
    SS[end - start + 1] = '\0';
    sscanf(SS, "%d", num);
    free(SS);
    if (num < 0) {
        return false;
    }
    return true;
}

void RecordSequence(int **ans, int num1, int num2, int *returnSize)
{
    *ans = (int*)malloc(sizeof(int) * (*returnSize));
    (*ans)[0] = num1;
    (*ans)[1] = num2;
    for (int i = 2; i < *returnSize; i++) {
        (*ans)[i] = (*ans)[i - 1] + (*ans)[i - 2];
    }
}

bool CheckSequence(char *S, int num1, int num2, int checkIndex, int *returnSize)
{
    DEBUGPRINT(printf("start checking:num1=%d, num2=%d\, checkindex=%d\n", num1, num2, checkIndex))
    *returnSize = 2;
    while (checkIndex < strlen(S)) {
        if (num1 < 0 || num2 < 0 || num1 > INT_MAX - num2) {
            *returnSize = 0;
            return false;
        }
        int nextNum = num1 + num2;
        int checkNum = S[checkIndex++] - '0';
        while (checkNum < nextNum) {
            DEBUGPRINT(printf("checkIndex=%d\n", checkIndex))
            if (checkIndex >= strlen(S)) {
                *returnSize = 0;
                DEBUGPRINT(printf("checkfalse\n"))
                return false;
            }
            if (checkNum > INT_MAX / 10) {
                *returnSize = 0;
                return false;
            }
            checkNum = checkNum * 10 + - '0' + S[checkIndex++];
            if (checkNum < 0) {
                *returnSize = 0;
                return false;
            }
            DEBUGPRINT(printf("checkNum=%d\n", checkNum))
        }
        if (checkNum > nextNum) {
            *returnSize = 0;
            DEBUGPRINT(printf("checkfalse:checkNum=%d\n", checkNum))
            return false;
        }
        if (checkNum == nextNum) {
            (*returnSize)++;
            num1 = num2;
            num2 = nextNum;
            DEBUGPRINT(printf("go on checking\n"))
        }
    }
    DEBUGPRINT(printf("check success, returnSize=%d\n", *returnSize))
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* splitIntoFibonacci(char *S, int *returnSize)
{
    int *ans = NULL;
    *returnSize = 0;
    for (int i = 0; i < strlen(S) - 2; i++) {
        /* no leading 0, should not greater than int */
        if ((i > 0 && S[0] == '0') || i > 9) {
            return ans;
        }
        for (int j = i + 1; j < strlen(S) - 1; j++) {
            /* no leading 0, should not greater than int */
            if ((j > i + 1 && S[i + 1] == '0') || j > i + 10) {
                break;
            }
            int num1, num2;
            if (!RetrieveOneNum(S, 0, i, &num1) || !RetrieveOneNum(S, i + 1, j, &num2)) {
                break;
            }
            if (CheckSequence(S, num1, num2, j + 1, returnSize)) {
                DEBUGPRINT(printf("%d\n", *returnSize))
                RecordSequence(&ans, num1, num2, returnSize);
                return ans;
            }
        }
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/solution/842cyu-yan-by-yewenhao-xx9n/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。