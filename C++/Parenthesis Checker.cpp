class Solution
{
    public:
    bool ispar(string x) {
        unordered_map<char, int> symbols { {'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
        stack<char> st;
        for(char bracket : x) {
            if(symbols[bracket] < 0){
                st.push(bracket);
            } else { 
                if(st.empty())return false;
                char topElement = st.top();
                st.pop();
                if(symbols[topElement] + symbols[bracket] != 0){
                    return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
