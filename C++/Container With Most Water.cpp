class Solution {
  public:
    int maxWater(vector<int> &arr) 
    {
        int left = 0;
        int right = arr.size() - 1;
        int ans = 0;
        while(left < right)
        {
            int maxWater = min(arr[left],arr[right]) * (right - left);
            ans = max(ans,maxWater);
            arr[left] < arr[right] ? left++ : right--;
        }
        return ans;
    }
};
