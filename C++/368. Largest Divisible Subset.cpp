class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int>dp(n+1, 1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(a[i] % a[prev] == 0  && dp[i] < dp[prev] +1){
                    dp[i] = 1+dp[prev];
                    maxi = max(maxi, dp[i]);
                }
              
            }
        }
        vector<int>ans;
        int prev = -1;
        for(int i=n-1;i>=0;i--){
           if(maxi == dp[i] && (prev % a[i] == 0  || prev == -1)){
               ans.push_back(a[i]);
               maxi = maxi-1;
               prev = a[i];
           }
           else continue;
        }
        cout<<endl;
        return ans;
        
    }
};
