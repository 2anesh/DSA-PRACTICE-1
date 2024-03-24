class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> newS;
        int y;
        while(!st.empty()){
            y = st.top();
            newS.push(y);
            st.pop();
        }
        st.push(x);
        while(!newS.empty()){
            y = newS.top();
            st.push(y);
            newS.pop();
        }
        return st;
    }
};
