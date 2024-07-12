class Solution {
  public:
    bool check(Node*root,int t,int sum)
  {
      if(!root)
      return false;
      if(root->left==NULL and root->right==NULL)
      {
          if(sum+root->data==t)return true;
          else return false;
      }
      return (check(root->left,t,sum+root->data)|| check(root->right,t,sum+root->data));
  }
    bool hasPathSum(Node *root, int target) {
     int sum=0;
      return check(root,target,sum);
    }
};
