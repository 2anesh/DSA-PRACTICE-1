class Solution
{
 public:
    bool checkPangram (string s) {
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z'){
                int val = int(s[i])-32;
                st.insert(char(val));
            }
             if(s[i]>='A' and s[i]<='Z'){
                
               st.insert(s[i]);
            }
        }
        return (st.size()==26);
    }

};
