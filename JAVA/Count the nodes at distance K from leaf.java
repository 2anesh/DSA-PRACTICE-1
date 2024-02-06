class Solution
{
    int printKDistantfromLeaf(Node root, int k)
    {
        if(root == null){
            return 0;
        }
        Queue<Node> q = new ArrayDeque<>();
        q.add(root);
        int c = 0;
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                Node curr = q.remove();
                if(solve(curr,k)){
                    c++;
                }
                if(curr.left != null){
                    q.add(curr.left);
                }
                if(curr.right != null){
                    q.add(curr.right);
                }
            }
        }
        return c;
    }
    public static boolean solve(Node root,int k){
        if(root == null){
            return false;
        }
        if((root.left  == null && root.right == null) && k == 0){
            return true;
        }
        if((root.left  == null && root.right == null) || k <= 0){
            return false;
        }
        boolean l = solve(root.left,k-1);
        boolean r = solve(root.right,k-1);
        return l || r;
        
    }

}
