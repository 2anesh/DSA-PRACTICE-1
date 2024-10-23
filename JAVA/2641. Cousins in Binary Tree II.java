class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int levelSum=root.val;
        while(!q.isEmpty())
        {
            int n = q.size();
            int nextLevelSum = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode curr = q.poll();
                curr.val = levelSum-curr.val;

                int siblingSum = curr.left!=null ? curr.left.val : 0;
                siblingSum += curr.right!=null ? curr.right.val : 0;

                if(curr.left!=null)
                {
                    nextLevelSum += curr.left.val;
                    curr.left.val = siblingSum;
                    q.add(curr.left);
                }
                 if(curr.right!=null)
                {
                    nextLevelSum += curr.right.val;
                    curr.right.val = siblingSum;
                    q.add(curr.right);
                }
            }
            levelSum = nextLevelSum;
        }
        return root;
    }
}
