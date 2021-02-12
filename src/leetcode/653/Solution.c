#include "Solution.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
第一步，遍历BST，把所有数值保存在一个线性的数组中，时间复杂度O(n)，空间复杂度O(n)
第二步，排序数组，时间复杂度O(nlgn)，如果第一步中使用中序遍历则第二步可省略
第三步，对于每一个数，bsearch查找是否存在另一个数与它的和时要求的，时间复杂度O(nlgn)
*/

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void Tree2Nums(struct TreeNode* root, int **nums, int *numsSize)
{
    if (root == NULL) {
        return;
    }
    (*numsSize)++;
    (*nums) = realloc(*nums, sizeof(int) * (*numsSize));
    (*nums)[*numsSize - 1] = root->val;
    Tree2Nums(root->left, nums, numsSize);
    Tree2Nums(root->right, nums, numsSize);
}

bool findTarget(struct TreeNode* root, int k)
{
    if (root == NULL) {
        return false;
    }
    int numsSize = 0, *nums;
    Tree2Nums(root, &nums, &numsSize);
    qsort(nums, numsSize, sizeof(int), &cmp);
    // printf("numsSize=%d\n", numsSize);
    for (int i = 0; i< numsSize; i++) {
        int key = k - nums[i];
        // printf("i=%d,nums[i]=%d,key=%d\n", i, nums[i], key);
        int *tmp = bsearch((const void*)&key, nums, numsSize, sizeof(int), &cmp);
        if (tmp!= NULL && tmp != nums + i) {
            // printf("%d+%d=%d\n", nums[i], *tmp, k);
            free(nums);
            nums = NULL;
            return true;
        }
    }
    free(nums);
    nums = NULL;
    return false;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/solution/653cyu-yan-by-yewenhao-2lup/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。