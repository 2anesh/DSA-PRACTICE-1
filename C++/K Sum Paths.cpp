class Solution {
  public:
    void solve(Node* node,int currsum,int k,unordered_map<int,int> &mp,int &cnt){
        if(!node)
        return;
        
        currsum+=node->data;
        
        if(currsum==k)
        cnt++;
        
        cnt+=mp[currsum-k];
        
        mp[currsum]++;
        
        solve(node->left,currsum,k,mp,cnt);
        solve(node->right,currsum,k,mp,cnt);
        
        mp[currsum]--;
        
    }
    int sumK(Node *root, int k) {
      int cnt=0;
      unordered_map<int,int> mp;
      solve(root,0,k,mp,cnt);
      return cnt;
    }
};
