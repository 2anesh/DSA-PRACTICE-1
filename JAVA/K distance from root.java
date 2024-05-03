class Tree
{
    void find(Node root,ArrayList<Integer> list,int k){
        if(root == null)return;
        if(k == 0)list.add(root.data);
        find(root.left,list,k-1);
        find(root.right,list,k-1);
    }
     ArrayList<Integer> Kdistance(Node root, int k)
     {
          ArrayList<Integer> list = new ArrayList<>();
          find(root,list,k);
          return list;
     }
}
