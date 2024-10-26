class Solution {
public:
    map<int, int> lh, rh, ht; 
    int height(TreeNode* root) {
        if (!root) return 0;
        int lr = height(root->left);  
        int rr = height(root->right); 
        lh[root->val] = lr; 
        rh[root->val] = rr;  
        return max(lr, rr) + 1;  
    }
    void solve(TreeNode* root, int maxHeightAbove, int depth) {
        if (!root) return;
        ht[root->val] = maxHeightAbove; 
        solve(root->left, max(maxHeightAbove, depth + rh[root->val]), depth + 1);
        solve(root->right, max(maxHeightAbove, depth + lh[root->val]), depth + 1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root); 
        solve(root->left, rh[root->val], 1); 
        solve(root->right, lh[root->val], 1); 
        vector<int> ans;
        for (int x : queries) {
            ans.push_back(ht[x]);  
        }
        return ans; 
    }
};
