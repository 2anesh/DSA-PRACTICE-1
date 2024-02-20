class Solution
{
public:
    int rec(int j, string &A, vector<string> &B, vector<int> &dp)
    {
        if(j == A.size())
            return 1;
        if(dp[j] != -1)
            return dp[j];
        string a = "";
        for(int idx=j;idx<A.size();idx++)
        {
            a += A[idx];
            int x = 0;
            for(auto i : B)
            {
                if(a == i)
                {
                    x = rec(idx+1, A, B, dp);
                }
            }
            if(x)
                return dp[idx] = x;
        }
        return dp[j] = 0;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        vector<int>dp(s.size(),-1);
        return rec(0, s, dictionary, dp);
    }
};
