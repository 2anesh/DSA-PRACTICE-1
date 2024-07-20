class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int c=0;        
        for(int i=0;i<s.size();i++){
            int j=spaces[c];
            if(i==j){
                ans+=" ";
                ans+=s[i];
                if(c+1<spaces.size()){
                    c++;
                }                               
            }else{
                ans+=s[i];
            }
        }
        return ans ;
    }
};
