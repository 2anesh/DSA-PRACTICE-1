class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        auto it1 = nums.begin();
        auto it2 = it1;
        int count = 0;
        int prev = 0, post = 0;
        unsigned int subs = 0;
        while(true){
            prev = 0;
            while(count < k && it2 != nums.end()){
                post = 0;
                count += (*it2) % 2;
                ++it2;
            }
            if(count != k) return subs;
            while( (*(it1++) % 2) == 0){
                ++prev;
            }
            while( it2 != nums.end() && (*it2 % 2) == 0){
                ++post;
                ++it2;
            }
            subs += 1 + prev * post + prev + post;
            --count;
        }
        return subs;
    }
};
