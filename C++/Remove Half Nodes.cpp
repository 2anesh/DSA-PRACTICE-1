class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        if(!root) return NULL;
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        Node *temp = root;
        if((!root->left and root->right) or (!root->right and root->left)){
            if(root->left) temp = root->left;
            else temp = root->right;
            root = NULL;
        }
        return temp;
    }
};
