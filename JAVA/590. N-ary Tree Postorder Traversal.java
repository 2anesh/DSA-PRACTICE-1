class Solution {
    public List<Integer> postorder(Node root) {
        ArrayList<Integer> list = new ArrayList<>();
        post(root,list);
        return list;
    }
    public void post(Node root,ArrayList<Integer> list )
    {
        if(root==null) return;
        for (Node child : root.children) post(child, list);
        list.add(root.val);
    }
}
