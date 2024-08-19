class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int>v(maxi+1,-1);
        for(int i=0;i<n;i++){
            v[arr[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<=maxi;i++){
            if(v[i]!=-1){
                cnt++;
                if(cnt==k){
                    return i;
                }
            }
        }
        return -1;
    }
};
