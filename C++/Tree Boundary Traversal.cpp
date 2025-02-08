class Solution {
    void leaf(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void left(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left ==NULL && root->right==NULL)
            return ;
        if(root->left ==NULL && root->right!=NULL){
            ans.push_back(root->data);
            left(root->right,ans);
        }else {
        
        ans.push_back(root->data);
        left(root->left,ans);
        }
         
    }
    void right(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left ==NULL && root->right==NULL)
            return ;
        if(root->left !=NULL && root->right==NULL){
            right(root->left,ans);
             ans.push_back(root->data);
        }
        else {
           right(root->right,ans);
           ans.push_back(root->data);
        }
         
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
         vector<int> ans ;
         Node* temp = root;
        if(temp->left ==NULL && temp->right==NULL) return {temp->data}; 
        ans.push_back(root->data);
        left(temp->left,ans); 
        leaf(temp,ans); 
        right(temp->right,ans); 
         
        return ans;
         
    }   
};
