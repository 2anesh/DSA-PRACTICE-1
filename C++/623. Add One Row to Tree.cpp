class Solution {
private:
    void helper(TreeNode* root,int val,int depth,int currDepth){       
        if(depth == currDepth+1){
            TreeNode*temp = new TreeNode(val);
            TreeNode*temp2 = new TreeNode(val);
            TreeNode*temp3 = root->left;
            TreeNode*temp4=root->right;            
            root->left=temp;
            root->right=temp2;            
            root->left->left = temp3;
            root->right->right=temp4;
            return ;
        }
       if(root->left != NULL) helper(root->left,val,depth,currDepth+1);
      if(root->right != NULL)  helper(root->right,val,depth,currDepth+1);        
        return ;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        helper(root,val,depth,1);
        return root;      
    }
};
