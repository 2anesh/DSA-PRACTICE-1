class Solution {
    int maxH, res;
    void solve(Node root, int ht, int sum) {
        if(root == null)
            return;
        
        if(root.left == null && root.right == null) {
            sum += root.data;
            
            if(ht > maxH) {
                maxH = ht;
                res = sum;
            } else if(ht == maxH) 
                res = Math.max(res, sum);
                
            return;
        }
        
        sum += root.data;
        solve(root.left, ht + 1, sum);
        solve(root.right, ht + 1, sum);
    }
    
    int sumOfLongRootToLeafPath(Node root) {
        maxH = res = 0;
        solve(root, 0, 0);
        return res;
    }
}
