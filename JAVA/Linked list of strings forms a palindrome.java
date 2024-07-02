class Solution {
    public boolean compute(Node root) {
        StringBuilder sb=new StringBuilder();
        while(root!=null)
        {
            sb.append(root.data);
            root=root.next;
        }
        if((sb.toString()).equals(sb.reverse().toString()))
            return true;
            
        return false;
    }
}
