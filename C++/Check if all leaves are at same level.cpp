class Solution{
    int maxi,mini;
    void checkHeight(Node* root, int i){
        if(!root) return;
        if(!root->left && !root->right){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        checkHeight(root->left, i+1);
        checkHeight(root->right, i+1);
    }
  public:
    bool check(Node *root)
    {
        if(!root) return true;
        maxi = 0, mini = INT_MAX;
        checkHeight(root,1);
        return maxi == mini;
    }
};
