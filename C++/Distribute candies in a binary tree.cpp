class Solution
{
public:
    int solve(Node *root, int &ans) 
    {
        if(!root) return 0;
        int lN = solve(root->left, ans);
        int rN = solve(root->right, ans);
        ans += abs(lN) + abs(rN);
        return root->key - 1 + lN + rN;
    }
    int distributeCandy(Node* root) 
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
