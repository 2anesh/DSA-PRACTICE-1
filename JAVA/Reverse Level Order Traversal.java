class Tree
{
    public ArrayList<Integer> reverseLevelOrder(Node root) 
    {
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Node> qu = new LinkedList<>();
        if(root != null)qu.add(root);
        while(qu.size() > 0){
            Node temp = qu.peek();
            if(temp.right != null)qu.add(temp.right);
            if(temp.left != null)qu.add(temp.left);
            Node t = qu.remove();
            ans.add(t.data);
        }
        Collections.reverse(ans);
        return ans;
    }
} 
