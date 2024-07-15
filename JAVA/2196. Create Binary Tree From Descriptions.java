class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;    
    TreeNode(int val) {
        this.val = val;
    }
}
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        Set<Integer> children = new HashSet<>();
        for (int[] desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            boolean isLeft = desc[2] == 1;           
            TreeNode parentNode = nodeMap.getOrDefault(parentVal, new TreeNode(parentVal));
            TreeNode childNode = nodeMap.getOrDefault(childVal, new TreeNode(childVal)); 
            if (isLeft) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }            
            nodeMap.put(parentVal, parentNode);
            nodeMap.put(childVal, childNode);            
            children.add(childVal);
        }
        TreeNode root = null;
        for (int val : nodeMap.keySet()) {
            if (!children.contains(val)) {
                root = nodeMap.get(val);
                break;
            }
        }        
        return root;
    }
}
