/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int finddepth(TreeNode root){
        if(root==null||(root.left==null&&root.right==null)) return 0;
        int depth=1;
        int ldepth=finddepth(root.left);
        int rdepth=finddepth(root.right);
        depth+=Math.max(ldepth,rdepth);
        return depth;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        int lans=0,rans=0,mans=0,ldepth=0,rdepth=0;
        //左子树直径
        if(root.left!=null){
            lans=diameterOfBinaryTree(root.left);
            ldepth=finddepth(root.left);
            mans++;
        }
        //右子树直径
        if(root.right!=null){
            rans=diameterOfBinaryTree(root.right);
            rdepth=finddepth(root.right);
            mans++;
        } 
        //必须穿过根节点时的最大长度
        mans+=ldepth+rdepth;
        //取三者中最大值
        return Math.max(mans,Math.max(lans,rans));
    }
}