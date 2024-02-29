class Solution{
public:
	 long long sumBitDifferences(int arr[], int n) {
        long ans=0;
        for(int i=31;i>=0;i--){
            long one=0,zero=0;
            for(int j=0;j<n;j++){
                int bit=1<<i;
                if((arr[j]&bit)>0)one++;
                else zero++;
            }
            ans+=(one*zero)*2;
        }
        return ans;
    }
};
