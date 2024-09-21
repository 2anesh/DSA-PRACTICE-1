class Solution {
    vector<int> ans;
    int num;
public:
    void helper(int n){
        if(n > num) return;
        ans.push_back(n);
        for(int i = 0; i<=9; i++){
            helper(n*10 + i);
        }
    }
    vector<int> lexicalOrder(int n) {
        ans = vector<int>(0);
        num = n;
        for(int i = 1; i<=9; i++) helper(i);
        return ans;
    }
};
