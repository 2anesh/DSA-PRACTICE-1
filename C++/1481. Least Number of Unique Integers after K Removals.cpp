class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto x:arr) mp[x]++;        
        vector<int> freq;
        for(auto x: mp) freq.push_back(x.second);
        sort(freq.begin(), freq.end());        
        int ans = freq.size();
        for(int i = 0; i < freq.size(); i++){
            if(k >= freq[i]){
                k -= freq[i];
                ans--;
            }else{
                break;
            }
        }
        return ans;
    }
};
