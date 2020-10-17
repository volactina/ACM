#include "Solution.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int abs(int a)
{
    return (a > 0) ? a : -a;
}

int height(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    return (abs(height(root->left) - height(root->right)) <= 1) &&
            isBalanced(root->left) && isBalanced(root->right);
}