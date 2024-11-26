class Solution {
  public:
     int circularSubarraySum(vector<int> &arr) {
        int big = INT_MIN, sum = 0, curr=0;
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            sum += arr[i];
            big = max(big, curr);
            
            if(curr < 0)
                curr = 0;
        }
        curr = 0;
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            big = max(big, sum - curr);
            
            if(curr > 0)
                curr = 0;
        }
        return big;
    }
};
