class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
         unordered_map<int,int>mp;
        long long suma=0,sumb=0;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            suma+=a[i];
        }
        for(int i=0;i<m;i++){
            sumb+=b[i];
        }
        if((suma+sumb)%2==1) return -1;
        suma=(suma+sumb)/2;
        for(int j=0;j<m;j++){
            long long reqNo=suma-sumb+b[j];
            if(mp.find(reqNo)!=mp.end()) return 1;
        }
        return -1;
    }
};
