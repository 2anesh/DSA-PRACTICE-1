class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        int count=0;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
            {
                int increment=arr[i-1]-arr[i]+1;
                arr[i]+=increment;
                count+=increment;
            }
        }
        return count;
    }
};
