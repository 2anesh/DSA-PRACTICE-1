class GfG 
{
    public static Tree convert(Node head, Tree node) {
        ArrayList<Tree> V=new ArrayList<>();
        Node temp=head;
        while(temp!=null){
            Tree treenode=new Tree(temp.data);
            V.add(treenode);
            temp=temp.next;
        }
        int n=V.size();
        for(int i=0;i<n/2;i++){
            if((2*i+1)<n){
               V.get(i).left=V.get(2*i+1);
            }
            if((2*i+2)<n){
                V.get(i).right=V.get(2*i+2); 
            }
        }
        return V.get(0);
    }
}  
