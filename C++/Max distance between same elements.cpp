class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int n = arr.size(), ans = 0;
        for(int i=0; i<n; i++){
            mp1[arr[i]] = i;
        }
        for(int i=n-1; i>=0; i--){
            mp2[arr[i]] = i;
        }
        for(auto it: mp2){
            ans = max(ans, abs(it.second-mp1[it.first]));
        }
        return ans;
    }
};
