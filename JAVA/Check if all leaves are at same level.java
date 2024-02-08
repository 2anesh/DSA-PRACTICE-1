class Solution
{
    boolean check(Node root)
    {
       Queue<Node> q=new LinkedList<>();
        q.add(root);
        q.add(null);
        int l=0;
        int p=0;
        while(!q.isEmpty()){
            Node k=q.poll();
            if(k==null){
                if(q.isEmpty()){
                    break;
                }else{
                    q.add(null);
                    l+=1;
                   continue; 
                }
            }
            if(k.left!=null){
                q.add(k.left);
            }
            if(k.right!=null){
                q.add(k.right);
            }
            if(k.left==null&&k.right==null){
                if(p!=0&&p!=l){
                    return false;
                }else{
                    p=l;
                }
            }
        }
        return true;
    }
}
