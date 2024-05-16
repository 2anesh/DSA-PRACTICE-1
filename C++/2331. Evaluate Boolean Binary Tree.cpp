class Solution {
private:
    bool inorder(TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            return root->val;
        }
        else{
            if(root->val==2){
                return inorder(root->left) || inorder(root->right);
            }
            return inorder(root->left) && inorder(root->right);
        }
    }
public:
    bool evaluateTree(TreeNode* root) {
        return inorder(root);
    }
};
