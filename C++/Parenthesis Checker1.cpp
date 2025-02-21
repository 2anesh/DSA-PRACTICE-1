class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for(auto ch:s){
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(st.empty())
                    return false;
                else if(ch==')' && st.top()=='(')
                    st.pop();
                else if(ch=='}' && st.top()=='{')
                    st.pop();
                else if(ch==']' && st.top()=='[')    
                    st.pop();
                else
                    return false;
                
            }
            
        }
        
        return st.empty();
    }
};
