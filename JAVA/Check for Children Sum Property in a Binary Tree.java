class Solution
{
    public static int isSumProperty(Node root)
    {
        if (root == null) return 1;
        if (root.left != null && root.right != null) {
            if (root.data != (root.left.data+root.right.data)) return 0;
        } else if (root.left != null) {
            if (root.data != (root.left.data)) return 0;     
        } else if (root.right != null) {
            if (root.data != (root.right.data)) return 0;      
        } else {
            return 1;
        }
        int left = isSumProperty(root.left);
        int right = isSumProperty(root.right);
        if (left == 0 || right == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}
