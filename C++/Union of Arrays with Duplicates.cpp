class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int>st;
        for(auto i:a)st.insert(i);
        for(auto i:b)st.insert(i);
        return st.size();
    }
};
