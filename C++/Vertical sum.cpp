class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        map<int,int> mp;
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* node = q.front().first;
            int pos = q.front().second;
            mp[pos] += node->data;
            q.pop();
            if(node->left)
                q.push({node->left,pos-1});
            if(node->right)
                q.push({node->right,pos+1});
        }
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};
