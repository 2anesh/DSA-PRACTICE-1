class Solution {
  public:
  bool isPossible(vector<int>& s, double mid, int k) {
        int cnt = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            cnt += ceil((s[i] - s[i - 1]) / mid) - 1;
        }
        return cnt <= k;
    }
    double findSmallestMaxDist(vector<int> & s, int k) {
        double st = 0.0;
        double en = s.back() - s.front(); 
        double ans = en;
        while (en - st > 1e-6) {
            double mid = st + (en - st) / 2.0;
            if (isPossible(s, mid, k)) {
                ans = mid;
                en = mid;
            } else {
                st = mid;
            }
        }
        return ans;
    }
};
