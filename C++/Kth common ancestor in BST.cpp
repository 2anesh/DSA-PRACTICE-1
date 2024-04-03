class Solution
{
    public:
   
    Node* Ancestor(Node* root,int x,int y,vector<int>&ans){
        
        if(root==NULL)
        return NULL;
        
        if(root->data==x || root->data==y){
            ans.push_back(root->data);
            return root;
        }
        
        if(root->data>x && root->data>y){
            ans.push_back(root->data);
            return Ancestor(root->left,x,y,ans);
        }
        if(root->data<x && root->data<y){
            ans.push_back(root->data);
            return Ancestor(root->right,x,y,ans);
        }
        ans.push_back(root->data);
        return root;
        
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        vector<int>ans;
        Node* LCA=Ancestor(root,x,y,ans);
        if(k==1)
        return LCA->data;
        if(ans.size()<k)
        return -1;
        return ans[ans.size()-k];
    }
};
