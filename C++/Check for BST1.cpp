class Solution {
  public:
    bool find(Node* root, int left, int right){
        if(!root){
            return true;
        }
        bool l = find(root->left,left,root->data);
        bool r = find(root->right,root->data,right);
        if(!l || !r || root->data<=left ||root->data>=right ){
            return false;
        }
        return true;
    }
    bool isBST(Node* root) {
        int left = INT_MIN;
        int right = INT_MAX;
        return find(root,left,right);
        
    }
};
