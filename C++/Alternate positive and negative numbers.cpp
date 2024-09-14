class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg; int a = 0, b = 0;
        for ( auto i : arr ) (i >= 0) ? pos.push_back(i) : neg.push_back(i);
        for ( int i = 0; i<arr.size(); i++ ){
            if ( i%2 == 0 ){ 
                if ( a < pos.size() ) arr[i] = pos[a++];
                else arr[i] = neg[b++];
            } else {
                if ( b < neg.size() ) arr[i] = neg[b++];
                else arr[i] = pos[a++];
            }
        }
    }
};
