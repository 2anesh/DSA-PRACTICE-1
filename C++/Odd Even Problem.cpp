class Solution {
  public:
    string oddEven(string s) {
        vector<int> v(27, 0);
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++){
            v[1+s[i]-'a']++;
        }
        for(int i=1; i<27; i++){
            if(v[i] > 0){
                if(i%2 == 0){
                    if(v[i]%2 == 0){
                        count++;
                    }
                }
                else{
                    if(v[i]%2 != 0){
                        count++;
                    }
                }
            }
        }
        if(count%2 == 0)
            return "EVEN";
        return "ODD";
    }
};
