class Solution {
  public:
    void in(Node* root,vector<int> &ans){
        if(!root) return ;
        
        in(root->left,ans);
        ans.push_back(root->data);
        in(root->right,ans);
    }
    bool is(vector<int> ans){
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]>=ans[i+1]) return false;
        }
        return true;
    }
    bool isBST(Node* root) {
        vector<int> ans;
        in(root,ans);
        return is(ans);
    }
};
