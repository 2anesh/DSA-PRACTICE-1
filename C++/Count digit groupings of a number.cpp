class Solution{
public:
int F(string &string,int ind,int sum,vector<vector<int>> &dp)
{
    if(ind==string.size())
    {
        return 1;
    }
    if(dp[ind][sum]!=-1)return dp[ind][sum];
    int temp=0,res=0;
    for(int i=ind;i<string.size();i++)
    {
       temp+=(string[i]-'0');
       if(temp>=sum)
       {
           res+=F(string,i+1,temp,dp);
       }
    }
    return dp[ind][sum]= res;
}
int TotalCount(string string){
    int n=string.size();
    vector<vector<int>> dp(n, vector<int>(1000, -1));
    return F(string,0,0,dp);
}
};
