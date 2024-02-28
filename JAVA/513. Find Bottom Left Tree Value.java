class Solution {
    int left_most_node_of_last_level = -999;
    public void breadth_first_search(TreeNode root_node){
        left_most_node_of_last_level = root_node.val;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root_node);
        while(!queue.isEmpty()){
            left_most_node_of_last_level = queue.peek().val;
            for(int i=1 , N = queue.size() ; (i <= N) ; i++){
                TreeNode current_node = queue.poll();
                if(current_node.left != null){
                    queue.add(current_node.left);
                }
                if(current_node.right != null){
                    queue.add(current_node.right);
                }
            }
        }
    }
    public int findBottomLeftValue(TreeNode root_node){
        breadth_first_search(root_node);
        return left_most_node_of_last_level;
    }
}
