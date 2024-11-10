class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        int i=0,j=0,n=a.size(),m=b.size();
        vector<int>res;
        while(i<n && j<m){
            if(a[i]==b[j]){
                res.push_back(a[i]);
                i++;
                j++;
                while(a[i]==res.back()) i++;
                while(b[j]==res.back())  j++;
            }else if(a[i]<b[j]){
                res.push_back(a[i]);
                i++;
            }else{
                res.push_back(b[j]);
                j++;
            }
        }
        
        while(i<n){
            while(i<n && a[i]==res.back())  i++;
            if(i==n)break;
            res.push_back(a[i]);
        }
  
        while(j<m){
            while(j<m && b[j]==res.back()) j++;
            if(j==m)break;
            res.push_back(b[j]);
        }
        
        return res;
    }
};
