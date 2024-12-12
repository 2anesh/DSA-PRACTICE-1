class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        
        for (int i = 0; i < k; i++) {
            if (gifts.front() <= 1) break;
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = floor(sqrt(gifts.back()));
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
