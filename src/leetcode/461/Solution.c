#include "Solution.h"

int hammingDistance(int x, int y)
{
    int cnt = 0;
    int z = x ^ y;
    while (z) {
        cnt += z & 1;
        z >>= 1;
    }
    return cnt;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/hamming-distance/solution/461cyu-yan-by-yewenhao-0zjn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。