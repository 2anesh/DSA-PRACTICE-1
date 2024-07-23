class Solution {
    ArrayList<Integer>list1;
    ArrayList<Integer>list2;
    public List<Integer> merge(Node root1, Node root2) {
        list1=new ArrayList<>();
        list2=new ArrayList<>();
        inorder(root1,list1);
        inorder(root2,list2);
        int i=0,j=0;
        ArrayList<Integer>res=new ArrayList<>();
        while(i<list1.size()&&j<list2.size()){
            if(list1.get(i)<=list2.get(j)){
                res.add(list1.get(i));
                i++;
            }else{
                res.add(list2.get(j));
                j++;
            }
        }
        while(i<list1.size()){
            res.add(list1.get(i));
            i++;
        }
        while(j<list2.size()){
            res.add(list2.get(j));
            j++;
        }
        return res;
    }
    public void inorder(Node root,ArrayList<Integer>list){
        if(root==null) return;
        inorder(root.left,list);
        list.add(root.data);
        inorder(root.right,list);
    }
}
