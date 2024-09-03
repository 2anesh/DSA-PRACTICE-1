class Solution {
public:
    int getLucky(string s, int k) {
        string converted = convert(s);
        int ans = 0;
        for(int i=0; i<k; i++){
            ans = transform(converted);
            converted = to_string(ans);
        }
        return ans;
    }
    string convert(string s){
        string temp = "";
        for(int i=0; i<s.size(); i++){
            int n = s[i]-'a'+1;
            temp += to_string(n);
        }
        return temp;
    }
    int transform(string s){
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            int n = s[i]-'0';
            ans += n;
        }
        return ans;
    }
};
