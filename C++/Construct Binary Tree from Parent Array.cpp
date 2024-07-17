class Solution {
  public:
    Node *createTree(vector<int> parent) 
    {
      Node* mp[10001]={NULL};
      Node* root;
      for(int i=0;i<parent.size();i++)
      {
          mp[i] = new Node(i);
          if(parent[i] == -1)
          root = mp[i];
      }
      for(int i=0;i<parent.size();i++)
      {
        if(parent[i]!=-1 && mp[parent[i]]->left == NULL)
        mp[parent[i]]->left = mp[i];
        else if(parent[i]!=-1 && mp[parent[i]]->right == NULL)
        mp[parent[i]]->right = mp[i];
      }
      return root;
    }
};
