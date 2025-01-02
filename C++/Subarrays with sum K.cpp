class Solution {
  public:
     int countSubarrays(vector<int> &arr, int k) 
    {
        int prefsum = 0;
        int count = 0;
        unordered_map <int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < arr.size(); i++)
        {
            prefsum += arr[i];
            count += mp[prefsum-k];
            mp[prefsum]++;
        }
        return count;
    }
};
