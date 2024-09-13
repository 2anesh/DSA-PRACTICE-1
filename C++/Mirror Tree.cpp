class Solution {
  public:
    void mirror(Node* root) {
        if(root == NULL) return;
        swap(root->left, root->right);
        if(root->left) mirror(root->left);
        if(root->right) mirror(root->right);        
    }
};
