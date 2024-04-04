class Solution {
public:
    int maxDepth(string s) {
        int i=0;
        int temp=0,count=0;
        stack <int> st;
        int n=s.length();
        while(i<n)
        {
            if(s[i]=='(')
            {
            st.push(s[i]);
            temp++;
            }
            else if(s[i]==')')
            {
                st.pop();
                temp--;
            }
            if(count<temp)
            count=temp;
            i++;
        }
        return count;
    }
};
