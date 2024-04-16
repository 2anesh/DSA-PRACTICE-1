class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1){
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }
        helper(root,1,val,depth);
        return root;
    }
    public void helper(TreeNode node , int count , int val , int depth){
        if(node == null) return;
        if(count == depth-1){
            TreeNode temp = node.left;
            node.left = new TreeNode(val);
            node.left.left = temp;
            temp = node.right;
            node.right = new TreeNode(val);
            node.right.right = temp;
        }else{
            helper(node.left , count+1 , val , depth);
            helper(node.right , count+1 , val , depth);
        }
        
    }
}
