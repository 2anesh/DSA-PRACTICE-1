class Solution {
    int moves = 0;
    public int distributeCoins(TreeNode root) {
        pot(root);
        return moves;
    }    
    public int pot(TreeNode node){
        if(node == null) return 0;
        int left = pot(node.left);
        int right = pot(node.right);        
        moves+=Math.abs(left)+Math.abs(right);
        return node.val-1+left+right;
    }
}
