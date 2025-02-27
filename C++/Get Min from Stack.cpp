class Solution {
   
  public:
    stack<int> st;
    int min;
    Solution() {
        // code here
    }
    void push(int x) {
        if(st.empty()) min = x;
        else
        {
            if(x<=min)
            {
                st.push(min);
                min=x;
            }
        }
        st.push(x);
        // code here
    }
    void pop() {
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        if(temp==min && !st.empty())
        {
            min= st.top();
            st.pop();
        }
    }
    int peek() {
        if(st.empty()) return -1;
        return st.top();
        // code here
    }
    int getMin() {
        if(st.empty()) return -1;
        return min;
        // code here
    }
};
