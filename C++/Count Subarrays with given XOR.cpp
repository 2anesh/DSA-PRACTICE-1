class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        map <int, int> mp;
        mp[0] = 1;
        int currXor = 0;
        long ans = 0;
        for(auto& e: arr){
            currXor = currXor^e;
            ans += mp[currXor^k];
            mp[currXor]++;
        }
        return ans;
    }
};
