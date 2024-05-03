class Solution
{
    private: 
    void solve(Node* root, vector<int>&ans, int k, int count){
        if(!root) return;
        if(count == k){
            ans.push_back(root -> data);
        }
        solve(root->left, ans, k, count+1);
        solve(root->right, ans, k, count+1);
    }
    public:
    vector<int> Kdistance(struct Node *root, int k)
    {
      vector<int> ans;
      if(k == 0){
          ans.push_back(root -> data);
          return ans;
      }
      solve(root -> left, ans, k, 1);
      solve(root -> right, ans, k, 1);
      return ans;
    }
};
