#include "Solution.h"

/*
方法一：O(sSize*log(gSize))
从最小的饼干开始给，对于每一块饼干，喂给能满足的最大的孩子（贪心）
要把饼干和孩子胃口都从小到大排序
对于每一块饼干去找能满足的最大的孩子，进行二分查找
方法二：O(gSize+sSize)
从最大的饼干开始给，对于每一块饼干，喂给能满足的最大的孩子（贪心）
把饼干和孩子胃口都从大到小排序
维护一个指针指向能被当前饼干满足的最大胃口的孩子（这个指针将只会递减，因为饼干大小只会越来越小），当这个指针指到最小胃口的孩子时就表明所有能被满足的孩子都被满足了（其他的孩子胃口太大满足不了了）
*/
int cmpReverse(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmpReverse);
    qsort(s, sSize, sizeof(int), cmpReverse);
    int MaxSatisfyChild = 0;
    int ans = 0;
    for (int i = 0; i < sSize; i++) {
        while (g[MaxSatisfyChild] > s[i]) {
            /* Cannot satisfy current child, so bring in the next child */
            MaxSatisfyChild++;
            if (MaxSatisfyChild == gSize) {
                /* still left some bisuits but no more kids can be satisfied */
                return ans;
            }
        }
        ans++;
        MaxSatisfyChild++;
        if (MaxSatisfyChild == gSize) {
            /* may still left some bisuits but no more kids can be satisfied */
            return ans;
        }
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/assign-cookies/solution/455cyu-yan-by-yewenhao-h24e/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。