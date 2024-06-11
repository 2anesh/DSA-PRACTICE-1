class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<vector<int>>vt;
        for(int i=0;i<n;i++){
            vt.push_back({abs(arr[i]-brr[i]),i});
        }
        sort(vt.rbegin(),vt.rend());
        int cnt1=0,cnt2=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            int indx=vt[i][1];
            if(arr[indx]>=brr[indx]){
                if(cnt1<x){
                    ans+=arr[indx];
                    cnt1++;
                }
                else{
                    ans+=brr[indx];
                    cnt2++;
                }
            }
            else{
                 if(cnt2<y){
                    ans+=brr[indx];
                    cnt2++;
                }
                else{
                    ans+=arr[indx];
                    cnt1++;
                }
            }
        }
        return ans;
    }
};
