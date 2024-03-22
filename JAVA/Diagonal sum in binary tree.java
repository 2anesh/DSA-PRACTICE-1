class Tree {
    public static ArrayList <Integer> diagonalSum(Node root) 
    {
        ArrayList<Integer> ans  = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
       while(!q.isEmpty())
       {
           int size = q.size();
           int sum = 0;
           for(int i=0;i<size;i++)
           {
               Node curr = q.poll();
               while(curr!=null)
               {
                   if(curr.left!=null)
                     q.add(curr.left);
                   sum += curr.data; 
                   curr = curr.right;
               }
                 
           }
           ans.add(sum);
       }
       return ans;
    }
}
