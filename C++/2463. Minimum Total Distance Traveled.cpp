class Solution {
public:
    long long maxValue  = 1e15;
    long long solve(int i , int j , vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>> &dp){
        if(i<0) return 0;
        if(j<0) return maxValue;

        long long min_dis  = maxValue;
        long long final_dis = 0;

        if(dp[i][j] != -1) return dp[i][j];

        min_dis = solve(i, j-1, robot, factory, dp);

        for(int l=0; l<factory[j][1] && i-l >=0; l++){
            final_dis = final_dis + abs(robot[i-l] - factory[j][0]);

            if(final_dis >= maxValue) break;

            min_dis = min(min_dis, final_dis + solve(i-l-1, j-1, robot, factory , dp));
        }

        return dp[i][j] = min_dis;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
         vector<vector<long long>> dp(n , vector<long long>(m, -1));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());


        return solve(n-1, m-1, robot, factory, dp);
    }
};
