class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int la=a.size(),lb=b.size();
        for(int i=lb-1;i>=0;i--) {
            a.push_back(b[i]);
            b.pop_back();
        }
        sort(a.begin(),a.end());
        for(int i=la+lb-1;i>=la;i--) {
            b.push_back(a[i]);
            a.pop_back();
        }
        reverse(b.begin(),b.end());
        return;
    }
};
