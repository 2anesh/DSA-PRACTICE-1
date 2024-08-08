class Solution {
    int f(Node node,boolean fl[]){
        if(node==null)return 0;
        if(node.left==null && node.right==null)return node.data;
        int left=f(node.left,fl);
        int right=f(node.right,fl);
        if(left+right!=node.data){
            fl[0]=false;
            return -1;
        }
        return left+right+node.data;
    }
    boolean isSumTree(Node root) {
        boolean fl[]={true};
        f(root,fl);
        return fl[0];
    }
}
