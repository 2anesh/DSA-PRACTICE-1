class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(root);
        Node * temp;
        
        while(!q.empty()){
            vector<int>curr;
            temp=q.front();
            q.pop();
            curr.push_back(temp->data);
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            
           ans.push_back(curr);
        }
        
        return ans;  
    }
};
