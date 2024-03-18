class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
      vector<int>v;
      queue<Node*>q;
      q.push(root);
      while(q.size()>0){
          Node* curr=q.front();
          q.pop();
          v.push_back(curr->data);
          if(curr->left!=NULL){
              q.push(curr->left);
          }
          if(curr->right!=NULL){
              q.push(curr->right);
          }
      }
      return v;
      
    }
};
