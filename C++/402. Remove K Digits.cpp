class Solution {
public:
    string removeKdigits(string &num, int k) {
        if(num.size() == k)
            return "0";
        stack<char> st;
        for(int i = 0 ; i < num.size() ; i++){
            while(!st.empty() && (st.top() > num[i]) && k){
                st.pop();
                k--;
            }
            if(num.size()-i == k){
                k--;
            }
            else st.push(num[i]);
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        num.clear();
        while(!st.empty()){
            num.push_back(st.top());
            st.pop();
        }
        reverse(num.begin(),num.end());
        return num.size() ? num : "0";
    }
};
