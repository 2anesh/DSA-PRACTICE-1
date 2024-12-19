class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n= arr.size();
        int l=0, r= n-1;
        if(arr[0]>k) return k;
        while(l<= r){
            int mid= (l+r)/2;
            int mCount= arr[mid]-(mid+1);
            if(mCount< k){
                l= mid+1;
            }
            else{
                r= mid-1;
            }
        }
        if(r== -1) return k;
        return k+r+1;
    }
};
