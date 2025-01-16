class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        unordered_map <int, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i < n; i++){
            sum += (arr[i] ? 1:-1);
            
            if(mp.find(sum) != mp.end()) ans = max(ans, i - mp[sum]);
            else mp[sum] = i;
        }
        
        return ans;
    }
};
