class Solution {
  public:
    string decodedString(string &s) {
        int n = s.length();
        if(n==0)return s;
        stack<int>st;
        stack<string>str;
        string temp = "";
        int num = 0;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[')
            {
                st.push(num);
                num = 0;
                str.push(temp);
                temp = "";
            }
            else if(s[i] == ']')
            {
                int k = st.top();
                st.pop();
                for(int j = 1; j<= k; j++)
                {
                    str.top() += temp;
                }
                temp = str.top();
                str.pop();
            }
            else
            {
                temp += s[i];
            }
        }
        return temp;
    }
};
