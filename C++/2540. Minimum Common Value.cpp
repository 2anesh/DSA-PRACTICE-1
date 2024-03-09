class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        unordered_set <int> numset(nums1.begin(), nums1.end());
        for(int i=0; i<nums2.size(); i++){
            if(numset.count(nums2[i])){
                ans = min(ans, nums2[i]);
            }
        }
        if(ans!=INT_MAX){
            return ans;
        }
        else{
            return -1;
        }
    }
};
