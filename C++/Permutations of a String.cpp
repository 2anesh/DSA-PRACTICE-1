class Solution {
  public:
  void combination(int start,set<string>&combi,string &s,int n)
  {
      if(start>=n)
      {
          combi.insert(s);
          return ;
      }
      
      for(int i=start;i<n;i++)
      {
          swap(s[start],s[i]);
          combination(start+1,combi,s,n);
          swap(s[start],s[i]);
      }
  }
    vector<string> findPermutation(string &s) {
        int n=s.size();
        set<string>combi;
        combination(0,combi,s,n);
        vector<string>ans(combi.begin(),combi.end());
        return ans;
    }
};
