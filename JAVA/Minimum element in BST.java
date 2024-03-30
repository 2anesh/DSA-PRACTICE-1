class Solution {
    int minValue(Node root) {
       return (root.left==null) ? root.data : minValue(root.left);
        
    }
}

