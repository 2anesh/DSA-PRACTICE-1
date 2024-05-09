class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int d = 0;
        int i = happiness.size() - 1;
        long long ans = 0;
        while(k > 0 && i >= 0){
            if(happiness[i] - d > 0){
                ans += (long long)(happiness[i] - d);
            }
            k--;
            i--;
            d++;
        }
        return ans;
    }
};
