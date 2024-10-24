class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {        
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL && root2 != NULL)
            return false;
        if(root1 != NULL && root2 == NULL)
            return false;        
        if(root1->val != root2->val)
            return false;
        swap(root1->left, root1->right);
        if(flipEquiv(root1->left, root2->left) && 
        flipEquiv(root1->right, root2->right))
        {
            return true;
        }
        swap(root1->left, root1->right);
        return flipEquiv(root1->left, root2->left) && 
        flipEquiv(root1->right, root2->right);
    }
};
