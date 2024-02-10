class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int num = 0;
        for(int i = 0; i < n; i++) {
            palindromic(s, i, i, num);  
            palindromic(s, i, i+1, num);
        }
        return num;
    }    
private:
    void palindromic(string s, int left, int right, int& num) { 
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            num++;
            left--;
            right++;
        }
    }
};
