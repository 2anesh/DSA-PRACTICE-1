class Solution {
public:
int minSteps(string s, string t) {
   vector<int> v(26, 0);
        for(char c: s) v[c - 'a'] ++;
        for(char c: t) v[c - 'a'] --;
        int ans = 0;
        for(int e: v) ans += abs(e);
        return ans / 2;
}
};
