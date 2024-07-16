class Solution {
    ArrayList<TreeNode> path1 = new ArrayList<>();
    ArrayList<TreeNode> path2 = new ArrayList<>();
    ArrayList<TreeNode> path3 = new ArrayList<>();
    TreeNode lca;
    public String getDirections(TreeNode root, int startValue, int destValue) {
        getPath(root, startValue, path1);
        getPath(root, destValue, path2);
        for(int i=0;i<path1.size() && i<path2.size(); i++){
            if(path1.get(i)!=path2.get(i)){
                break;
            }else{
                lca = path1.get(i);
            }
        }
        String ans="";
        getPath(lca,startValue,path3);
        for(int i=0;i<path3.size()-1;i++){
            ans+="U";
        }
        StringBuilder k= new StringBuilder("");
        getPath2(lca,destValue,k);
        System.out.println(k.toString());
        return ans+k.toString();
    }
    public boolean getPath(TreeNode root, int dest, ArrayList<TreeNode> path){
        if(root==null){
            return false;
        }
        path.add(root);
        if(root.val==dest){
            return true;
        }
        boolean foundLeft = getPath(root.left,dest,path);
        boolean foundRight = getPath(root.right,dest,path);
        if(foundLeft || foundRight){
            return true;
        }
        path.remove(path.size()-1);
        return false;
    }
    public boolean getPath2(TreeNode root, int dest, StringBuilder ans) {
        if (root == null) {
            return false;
        }
        if (root.val == dest) {
            return true;
        }        
        ans.append('L');
        if (getPath2(root.left, dest, ans)) {
            return true;
        }
        ans.deleteCharAt(ans.length() - 1);        
        ans.append('R');
        if (getPath2(root.right, dest, ans)) {
            return true;
        }
        ans.deleteCharAt(ans.length() - 1);        
        return false;
    }
}
