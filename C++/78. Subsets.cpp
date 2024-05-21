class Solution {
public:    
    vector<vector<int>> ans;    
    void help(vector<int> v,int c){        
        int n = v.size();        
        vector<int> t;        
        for(int i=0;i<n;i++){
            int x = (c&1);            
            if(x) t.push_back(v[i]);            
            c>>=1;
        }        
        ans.push_back(t);
    }    
    vector<vector<int>> subsets(vector<int>& v) {        
        int n = v.size();        
        for(int i=0;i<(1<<n);i++) help(v,i);        
        return ans;        
    }
};
