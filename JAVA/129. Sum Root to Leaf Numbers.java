class Solution {
    public int sumNumbers(TreeNode root) {
        return sumtree(root ,0);
    }
    public int sumtree(TreeNode root ,int n){
        if(root == null)return 0;
        n=n*10+root.val;
        if(root.right==null&&root.left==null)return n;
        return sumtree(root.right ,n)+sumtree(root.left,n);
    }
}
