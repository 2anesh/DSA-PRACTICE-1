class Solution {
public:
int ans=0;
vector<int> res ;
void solve(int n)
{
    if(ans == 0)
    {
        ans += n;
    }
    else {
        ans *= 10;
        ans += n;
    }
}
void inorder(TreeNode* root)
{
    if(root == NULL)
        return;    
    solve(root->val);
    if(root->left == NULL && root->right == NULL)
    {
        res.push_back(ans);
    }
    inorder(root->left);
    inorder(root->right);
    ans /=10;
}
int sumNumbers(TreeNode* root) {
    inorder(root);
    int sum =0;
    for(int i=0; i<res.size(); i++)
    {
        sum += res[i];
    }
    return sum;
}
};
