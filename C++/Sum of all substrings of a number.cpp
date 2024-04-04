class Solution
{
    public:
    const int mod = 1000000007;
    long long sumSubstrings(string s){
        long long ans = 0, temp = 0;
        int n = s.size();
        for (int i = 0; i < n; i++){
            temp = temp * 10 + (i + 1) * (s[i] - '0');
            temp %= mod;
            ans += temp;
            ans %= mod;
        }
        return ans;
    }
};
