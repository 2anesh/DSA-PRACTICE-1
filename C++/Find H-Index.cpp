class Solution {
 public: 
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        for(int i = 0; i<n; i++){
            int cnt = n-i;
            if(citations[i]>=cnt) return cnt;
        }
        return 0;
    }
};
