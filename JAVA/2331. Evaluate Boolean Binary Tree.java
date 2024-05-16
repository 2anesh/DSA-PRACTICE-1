class Solution {
    public boolean evaluateTree(TreeNode root) {
         if(root == null) return false;        
        int rootValue = root.val;        
        boolean leftValue = evaluateTree(root.left);
        boolean rightValue = evaluateTree(root.right);        
        if(rootValue == 0) return false;
        if(rootValue == 1) return true;        
        if(rootValue == 2) return leftValue || rightValue;
        if(rootValue == 3) return leftValue && rightValue;        
        return false;
    }
}
