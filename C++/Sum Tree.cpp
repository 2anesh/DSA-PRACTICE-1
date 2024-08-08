class Solution {
  public:
   int sum(Node *root){
      if(root==NULL) return 0;
      return root->data+sum(root->left)+sum(root->right);
  }
    bool isSumTree(Node* root) {
        if(root==NULL || root->left==NULL && root->right==NULL) return true;
        if(root->data==sum(root->left)+sum(root->right) && isSumTree(root->left) && isSumTree(root->right)){
            return true;
        }
        return false;
    }
};
