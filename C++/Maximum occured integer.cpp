class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int>arr(maxx+2,0);
        for(int i=0;i<n;i++){
            arr[l[i]]++;
            arr[r[i]+1]--;
        }
        int sum=0;
        for(int i=0;i<=maxx;i++){
            arr[i]+=sum;
            sum=arr[i];
        }
        int ans=0;
        for(int i=1;i<=maxx;i++){
            if(arr[i]>arr[ans]){
                ans=i;
            }
        }
        return ans;
    }
};
