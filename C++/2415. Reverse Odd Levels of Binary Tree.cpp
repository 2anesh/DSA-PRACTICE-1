class Solution {
public:
    void helper(TreeNode* a, TreeNode* b, int l){
        if(a==NULL || b==NULL){
            return;
        }
        if(l%2!=0){
            int temp=a->val;
            a->val=b->val;
            b->val=temp;
        }
        helper(a->left,b->right,l+1);
        helper(a->right,b->left, l+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, 1);
        return root;
    }
};
