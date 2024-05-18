class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int n=arr.size();
        int low=0,high=n-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (mid==n-1){
                high=mid-1;
                continue;
            }
            if (arr[mid]<arr[mid+1] ){
                low=mid+1;
            }
            else if (arr[mid]>=arr[mid+1]  ){
                high=mid-1;
            }
        }
        return arr[low];
    }
};
