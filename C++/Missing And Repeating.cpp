class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
            if(mp[it]>1){
                ans = it;
            }
        }
        int an = 0;
        for(int i=1; i<=n; i++){
            if(mp[i]==0){
                an = i;
                break;
            }
        }
        return{ans, an};
    }
};
