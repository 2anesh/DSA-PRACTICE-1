class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int ele1=0;
        int cnt2=0;
        int ele2=0;
        for(int i=0;i<n;i++){
             if(ele1==nums[i]){
                cnt1++;
            }
         else if(ele2==nums[i]){
                cnt2++;
            }
           else if(cnt1==0){
                cnt1=1;
                ele1=nums[i];
            }
         else if(cnt2==0){
                cnt2=1;
                ele2=nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
          cnt1 = 0, cnt2 = 0;
          vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 > n / 3) ans.push_back(ele1);
        if(cnt2 > n / 3 && ele2 != ele1) ans.push_back(ele2);
        if(ans.empty()) return {-1};
        return ans;
    }
};
