class Solution {
    int value = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        process(root);
        return value;
    }
    public void process(TreeNode root)
    {
        if (root!=null)
        {
            if (root.left != null && root.left.left == null && root.left.right == null)
                value += root.left.val;
            process(root.left);
            process(root.right);
        }
    }
}
