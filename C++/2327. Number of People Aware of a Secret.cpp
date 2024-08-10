class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD=1000000007;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<=n;i++){
            if(dp[i]!=0){
                int s=i+delay;
                int e=i+forget;
                while(s<=n && s<e){
                    dp[s]=(dp[s]%MOD+dp[i]%MOD)%MOD;
                    s++;
                }
            }
        }        
        int tot=0;
        for(int i=n-forget+1;i<=n;i++){
            tot=(tot%MOD+dp[i]%MOD)%MOD;
        }        
        return tot%MOD;
    }
};
