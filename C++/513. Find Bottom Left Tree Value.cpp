class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int ct=q.size();            
            for(int i=0;i<ct;i++)
            {
                TreeNode*ptr=q.front();
                q.pop();                
                if(ptr->left!=NULL)
                    q.push(ptr->left);
                if(ptr->right!=NULL)
                    q.push(ptr->right);                
                if(i==0)
                    ans=ptr->val;
            }
              
        }        
        return ans;
    }
};
