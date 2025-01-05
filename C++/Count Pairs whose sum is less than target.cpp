class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int count=0 , l =0, r = arr.size()-1;
        while(l<r){
            if(arr[l]+arr[r] >= target) r--;
            if(arr[l]+arr[r]<target)count+=(r-l),l++;
        }
        return count;
    }
};
