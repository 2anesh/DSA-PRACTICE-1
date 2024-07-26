class Solution {
  public:
  bool kPangram(string str, int k) {
        vector<int> freq(26);
        for(const char & ch : str){
            if(ch <= 'z' && ch >='a')
                freq[ch-'a']++;
        }
        int extra=0,empty=0;
        for(size_t i=0; i<26; i++){
            if(freq[i] == 0){
                empty++;
            }else{
                extra += freq[i]-1;
            }
        }
        if(empty <= extra && empty <= k){
            return true;
        }
        return false;
    }
};
