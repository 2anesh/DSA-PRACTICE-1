class GfG {
    Node cans(Node root,int a,int b)
    {
        if(root==null||root.data==a||root.data==b) return root;
        Node ln=cans(root.left,a,b);
         Node rn=cans(root.right,a,b);
         if(rn==null) return ln;
         if(ln==null) return rn;
         return root;
    }
    int dist(Node root,int a)
    {
        if(root==null) return -1;
        else if(root.data==a) return 0;
        int ld=dist(root.left,a);
        int rd=dist(root.right,a);
        if(ld>=0) return ld+1;
        return (rd>=0)?rd+1:-1;
        
    }
    int findDist(Node root, int a, int b)
    {
       Node nn=cans(root,a,b);
       int ld=dist(nn,a);
       int rd=dist(nn,b);
       return ld+rd;
    }
}
