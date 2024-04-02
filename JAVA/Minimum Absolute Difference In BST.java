class Solution
{
    
    int prev;
    int diff;
    
    int absolute_diff(Node root)
    {
        prev = Integer.MIN_VALUE;
        diff = Integer.MAX_VALUE;
        
        findMinDiff(root);
        return diff;
    }
    
    void findMinDiff(Node root){
        if(root == null)
            return;
            
        findMinDiff(root.left);
        if(prev!= Integer.MIN_VALUE && Math.abs(prev-root.data) < diff){
            diff = Math.abs(prev-root.data);
        }
        prev = root.data;
        
        findMinDiff(root.right);
    }
}
