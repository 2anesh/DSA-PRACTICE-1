class Solution {
public:
    void remove(string &s, stack<char>& st) {
        string temp = "";
        bool found = false;
        for (int i = 0; i < s.length(); ++i) {
            if (i < s.length() - 1 && 
               ((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D'))) {
                i++; 
                found = true;
            } else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());  
        s = temp;
        if (found) {
            remove(s, st);
        }
    }
    int minLength(string s) {
        stack<char> st;
        remove(s, st); 
        return s.length(); 
    }
};
