class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        vector<int>v;       
      int z=0;
        for(int i=0;i<a.size();i++)
        {
            z=z^a[i];
            v.push_back(z);
        }
                vector<int>ans;        
        for(int i=0;i<q.size();i++)
        {
            int a=q[i][0];
            int b=q[i][1];
            int k=0;
            if(a-1>=0)
             k=v[b]^v[a-1];
            else
                k=v[b];
            ans.push_back(k);
        }
        return ans;
    }
};
