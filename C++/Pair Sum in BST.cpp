class Solution {
  public:
    vector<int> ans;

    void solve(Node* root) {
        if (root == NULL) return;
        solve(root->left);
        ans.push_back(root->data);
        solve(root->right);
    }
    
    bool findTarget(Node *root, int target) {
        ans.clear();
        solve(root);
        sort(ans.begin(),ans.end());
        
        int i=0;
        int j= ans.size()-1;
        
        while(i<j){
            int temp = ans[i]+ans[j];
            if(ans[i]+ans[j]==target){
                return true;
            }else if(ans[i]+ans[j]<target){
                i++;
            }else if(ans[i]+ans[j]>target){
                j--;
            }
           
        }
        return false;
        
        
    }
};
