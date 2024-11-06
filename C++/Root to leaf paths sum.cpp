class Solution {
  public:
    void solve(Node* root, int num, int &sum){
        if(root->left==NULL && root->right==NULL){
            sum += (10*num + root->data);
            return;
        }
        if(root->left) solve(root->left, 10*num + root->data, sum);
        if(root->right) solve(root->right, 10*num + root->data, sum);
    }
    int treePathsSum(Node *root) {
        int num = 0;
        int sum = 0;
        solve(root, num, sum);
        return sum;
        
    }
};
