class Solution {
public:
    vector<int> longestSubarray(vector<int>& a, int x) {
        multiset<int> st;
        int maxi = 0, curr = 0, ind = 0;
        int j = 0, n = a.size();

        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
            curr++;

            while (*st.rbegin() - *st.begin() > x) {
                st.erase(st.find(a[j++]));
                curr--;
            }

            if (curr > maxi) {
                maxi = curr;
                ind = i;
            }
        }

        return vector<int>(a.begin() + ind - maxi + 1, a.begin() + ind + 1);
    }
};

