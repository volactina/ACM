#include "Solution.h"

/*
题目实际上是求给定序列中最长的最多包含2个不同数字的子序列有多长
特殊情况就是全都是一个数字那就是全部选中（如果想排除这种情况那么可以加上伪树-1）
用双指针的方法去持续维护至多包含2种不同数字的区间，整个维护过程种最长的值就是答案
*/
int totalFruit(int* tree, int treeSize)
{
   int num1, num2, last1, last2, ans, p1, p2, numSize;
   ans = 1;
   p1 = 0;
   p2 = 1;
   while (p1 < treeSize && p2 < treeSize) {
       last1 = p1;
       num1 = tree[p1];
       numSize = 1;
       for (p2 = p1 + 1; p2 < treeSize; p2++) {
           if (tree[p2] == num1) {
               last1 = p2;
               ans = (ans < p2 - p1 + 1) ? p2 - p1 + 1 : ans;
               continue;
           }
           /* tree[p2] != num1 */
           if (numSize == 1) {
               numSize++;
               num2 = tree[p2];
               last2 = p2;
               ans = (ans < p2 - p1 + 1) ? p2 - p1 + 1 : ans;
               continue;
           }
           /* tree[p2] != num1 && numSize == 2 */
           if (tree[p2] != num1 && tree[p2] != num2) {
               /* reset p1 to make the interval contains only one kind of number */
               p1 = ((last1 < last2) ? last1 : last2) + 1;
               break;
           }
           ans = (ans < p2 - p1 + 1) ? p2 - p1 + 1 : ans;
       }
   }
   return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/fruit-into-baskets/solution/904cyu-yan-by-yewenhao-vmm7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。