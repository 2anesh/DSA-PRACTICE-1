class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int idx=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        int i=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        return idx-i;
    }
};
