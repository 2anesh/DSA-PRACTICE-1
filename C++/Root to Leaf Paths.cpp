class Solution {
  private:
    void travel(Node* root, vector<vector<int>>&ans, vector<int> curr){
        if(root == NULL){
            return;
        }
        curr.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(curr);
            return;
        }
        travel(root->left, ans, curr);
        travel(root->right, ans, curr);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> curr;
        travel(root, ans, curr);
        return ans;
    }
};
