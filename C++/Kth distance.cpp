class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if (mp[arr[i]] > 0) {
                return true;
            }

            mp[arr[i]]++; 
            if (i >= k) {
                mp[arr[i - k]]--; 
            }
        }
        return false;
    }
};
