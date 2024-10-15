class Solution {
public:
    long long minimumSteps(string s) {
        int zero = 0;
        for(auto it:s) if(it=='0') zero++;
        int i = 0;
        int j = 0;
        long long ans = 0;
        int pos = zero;
        while(zero>0 & j<s.size()){
            if(s[j]=='1'){
                ans +=pos-j;
                pos++;
            }
            else{
               zero--;
            }
            j++;
        }
        return ans;
    }
};
