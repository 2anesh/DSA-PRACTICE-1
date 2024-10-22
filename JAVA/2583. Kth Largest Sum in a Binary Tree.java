class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
      Queue<TreeNode> q = new LinkedList<>();
      q.add(root);
      List<Long> list = new ArrayList<>();
      while(!q.isEmpty())
      {
        int size = q.size();
        long total = 0;
        for(int i=0;i<size;i++)
        {
            TreeNode temp = q.poll(); 
            total+=temp.val;
            if(temp.left!=null)
            q.add(temp.left);
            if(temp.right!=null)
            q.add(temp.right);
        }
        list.add(total);
      }  
      if(k>list.size())
      return -1;
      Collections.sort(list);
      return list.get(list.size()-k);
    }
}
