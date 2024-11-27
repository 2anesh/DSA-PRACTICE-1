class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int idx=0;
        while(idx<arr.size() && arr[idx]<=0)    
        {
            idx++;
        }
        int val=1;
        while(idx<arr.size() && arr[idx]==val)
        {
            while(idx<arr.size()-1 && arr[idx]==arr[idx+1])
            {
                idx++;
            }
            idx++;
            val++;
        }
        return val;
    }
};
