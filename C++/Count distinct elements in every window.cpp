class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = arr.size();
        int start =0;
        for(int i= 0;i <n;i++){
           mp[arr[i]]++;
           if(i -start + 1 == k){
               ans.push_back(mp.size());
               mp[arr[start]]--;
               if(mp[arr[start]] == 0){
                   mp.erase(arr[start]);
               }
               start++;
           }
            
        }
        return ans;
    }
};
