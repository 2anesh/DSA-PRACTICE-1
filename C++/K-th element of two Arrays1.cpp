class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> v;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++){
            v.push_back(a[i]);
        }
        for(int j=0;j<m;j++){
            v.push_back(b[j]);
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};
