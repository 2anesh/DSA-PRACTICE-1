class Solution {
  public:
     int findPair(int n, int x, vector<int> &arr) 
    {
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++)
        {
            int low = i;
            int high = n-1;
            while(low <= high)
            {
                int mid = (low + high)/2;
                if((arr[mid] == arr[i] + x) && (mid != i))
                    return 1;
                else if(arr[mid] > arr[i] + x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
