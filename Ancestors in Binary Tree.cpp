class Solution {
  public:
    bool trav(struct Node *root, int target,vector<int>&ans)
    {
        if(root==NULL)
        return false;
        
        if(root->data==target)
       {
            return true ;
       }
      bool lt= trav(root->left,target,ans);
       bool rt=trav(root->right,target,ans);
       if(lt||rt)
        {
            ans.push_back(root->data);
        }
        return lt||rt;
        
    }
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        trav(root,target,ans);
        return ans;
    }
};
