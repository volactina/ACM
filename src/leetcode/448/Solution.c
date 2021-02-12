#include "Solution.h"

/*
第一步，在原数组中进行操作，把原数组搞成每个数字i都在第i处位置（编程实现时要考虑一下起始是0，这里假设起始是1），如果第i处位置没有数字就放0，这个要在O(n)时间内搞定
第二步就是对第一步拿到的数组扫一遍，把放0位置的index记录下来就是答案
第一步怎么在O(n)时间内完成呢？只要从左到右对每一个元素进行如下操作即可：
对于每一个位置i的元素，假设[1..i-1]都已经放置正确了（放置正确表示要么第k处放k,要么第k处放0表示不存在
(1)如果位置i已经放置正确（即放置了i或0）则去看下一个位置i+1的元素
(2)如果位置i没有放置正确，放了j，则去看位置j放了什么：
a.如果位置j放了j，则把位置i置为0————这种情况j就是出现了2次的数字，这个操作相当于把j放到位置j去
b.否则就交换位置j和位置i放置的数字————如果位置j放的数不是0，这个操作就是把j放到正确的位置去，然后把位置j本来的数给挪出来；如果位置j放的数是0，这个操作就是把j放到该放的位置去，然后位置i处就没有数字（所以就置为0了）
(3)重复执行1-3步
这里从左到右遍历最多进行n次，进行交换放置的操作也最多进行n次（因为每交换一次一定会导致放置在正确位置上的元素个数多1）
*/
void SwapNum(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != 0 && nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) {
                nums[i] = 0;
                (*returnSize)++;
            } else {
                SwapNum(&nums[i], &nums[nums[i] - 1]);
            }
        }
    }
    int *ans = NULL;
    if (*returnSize == 0) {
        return ans;
    }
    ans = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0, t = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            ans[t++] = i + 1;
        }
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/448-by-yewenhao-4mdt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。