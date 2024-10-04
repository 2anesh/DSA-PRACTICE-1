class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long sum = 0;
        long long tempsum = skill[0] + skill[n - 1];
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            long long currsum = skill[i] + skill[j];
            if (tempsum != currsum) {
                return -1;
            }
            sum += (long long)skill[i] * skill[j];
        }
        return sum;
    }
};
