class Solution {
public:
 vector<int> arr;
void postorder(TreeNode * root)
{
    if(root==NULL)
        return ;
     postorderTraversal(root->left);
        postorderTraversal(root->right);
        arr.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {       
        postorder(root);
        return arr;
    }
};
