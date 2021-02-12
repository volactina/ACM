#include "Solution.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*
O(k)算法采用组合数递推公式，C(i,k)=C(i-1,k)*(k-i+1)/i
 */
int* getRow(int rowIndex, int* returnSize)
{
    int *ans = malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    ans[0] = 1;
    for (int i = 1; i < rowIndex + 1; i++) {
        ans[i] = (long)ans[i - 1] * (rowIndex + 1 - i) / i;
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/pascals-triangle-ii/solution/119cyu-yan-by-yewenhao-xs5o/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。