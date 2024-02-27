class Solution {
    int maxDia = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return maxDia;
    }
    public int maxDepth(TreeNode root){
        if (root == null){
            return 0;
        }
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        int myDia = leftDepth + rightDepth;
        maxDia = Math.max(myDia, maxDia);
        int res = Math.max(leftDepth, rightDepth) + 1;
        return res;
    }
}
