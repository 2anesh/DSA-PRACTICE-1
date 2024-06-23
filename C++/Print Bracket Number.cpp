class Solution { 
  public:
    vector<int> bracketNumbers(string str) {
        stack<pair<char, int>> st;
        vector<int> ans;
        int maxi = 0;
        for(auto it: str){
            if(it == '('){
                maxi++;
                st.push({'(', maxi});
                ans.push_back(maxi);
            }
            else if(it == ')'){
                ans.push_back(st.top().second);
                st.pop();
            }
        }
        return ans;
    }
};
