class Solution {
public:
    bool isPalin(string a) {
        for(int i = 0; i < a.length()/2; i++) {
            if(a[i] != a[a.length() - i -1])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i : words) {
            if(isPalin(i))
                return i;
        }
        return "";
    }
};
