class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& p, int L, int M) {
        int sz = p.size(), lt = 0, ltm = 0, mt = 0, mtm = 0, res = 0, mx = 0;
        if (L > M) { int t = M; M = L; L = t; }
        int mtmx[sz], ltmx[sz], mtms[sz], ltms[sz];
        for (int i = 0; i < sz; i++) {
            p[i] = p[i] + (i ? p[i - 1] : 0);
            if (i >= M - 1) { mt = p[i] - (i < M ? 0 : p[i - M]); mtm = max(mtm, mt); }
            if (i >= L - 1) { lt = p[i] - (i < L ? 0 : p[i - L]); ltm = max(ltm, lt); }
            mtms[i] = mt; ltms[i] = lt; mtmx[i] = mtm; ltmx[i] = ltm;
            if (i >= M) {
                mx = max(mx, max(mtms[i] + ltmx[i - M], ltms[i] + mtmx[i - L]));
            }
        }
        return mx;
    }
};
