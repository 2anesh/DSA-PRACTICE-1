class Solution {
public:
    int majorityElement(vector<int>& n) {
        map<int,int> m;
        int th = n.size()/2;
        for(auto i : n){
            if (++m[i] > th) return i;
        }
        return n[0];
    }
};
