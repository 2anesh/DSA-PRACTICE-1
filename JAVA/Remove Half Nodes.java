class Solution {
    public Node help(Node node){
      if(node==null)return null;
      node.left=help(node.left);
      node.right=help(node.right);
      if(node.left==null && node.right==null) return node;
      else if(node.right==null) return node=node.left;
      else if(node.left==null)  return  node=node.right; 
    return node;
    }
    public Node RemoveHalfNodes(Node root) {
        Node ans=help(root);
        return ans;
    }
  }
