class Solution{
public:
    long long sequence(int n){
        int mod = 1e9 + 7;
        int cnt = 0;
        long long res = 0;
        for(int i=1; i<=n; i++)
        {
            long long int temp = 1;
            for(int j=1; j<=i; j++)
            {
                cnt++;
                temp = (temp * cnt) % mod;
            }
            res = (res + temp) % mod;
        }
        return res;
    }
};
