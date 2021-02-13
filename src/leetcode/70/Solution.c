#include "Solution.h"

#define MAXN 100
/* f(n)=f(n-1)+f(n-2),f(0)=1,f(1)=1*/
/* 记忆化 */
int climbStairs(int n)
{
    int f[MAXN];
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/climbing-stairs/solution/70cyu-yan-by-yewenhao-3o4a/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。