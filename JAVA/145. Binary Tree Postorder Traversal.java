class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
       List<Integer> l1=new ArrayList();
       return traversal(root,l1);
    }
    public List<Integer>traversal(TreeNode root,List<Integer> arr){
        if(root!=null){           
            traversal(root.left,arr);
            traversal(root.right,arr);
             arr.add(root.val);
        }
        return arr;
    }  
}
