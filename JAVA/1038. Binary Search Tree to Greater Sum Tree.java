class Solution {
    int cursum = 0; 
    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        return root;
    }
    public void dfs(TreeNode root) {
        if (root == null) {
            return; 
        }
        dfs(root.right);
        int temp = root.val; 
        root.val += cursum; 
        cursum += temp; 
        dfs(root.left);
    }
}
