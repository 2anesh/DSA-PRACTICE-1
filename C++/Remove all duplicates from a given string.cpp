class Solution{
public:
    string removeDuplicates(string str) {
        string res="";
        int n= str.length();
       unordered_set<char>st;
        
        for(int i=0; i< n; i++){
            char ch=str[i];
           if(st.find(ch)!=st.end()) 
                continue;
           else
           {
                st.insert(ch);
                res+=ch;
           }
        }
        return res;
    }
};
