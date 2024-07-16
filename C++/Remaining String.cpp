class Solution {
  public:
    string printString(string s, char ch, int count) {
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==ch)count--;
            if(count==0){
                if(i==n-1)return "";
                return s.substr(i+1,n-i+1);
            }
        }
        return "";
    }
};
