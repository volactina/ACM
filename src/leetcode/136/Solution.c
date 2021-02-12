#include "Solution.h"

int singleNumber(int* nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/single-number/solution/136cyu-yan-by-yewenhao-czug/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。