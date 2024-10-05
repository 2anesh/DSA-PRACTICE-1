class Solution {
private: 
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds); 
            return; 
        }
        for(int i = 0;i<nums.size();i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1; 
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0; 
                ds.pop_back(); 
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        int freq[nums.size()]; 
        for(int i = 0;i<nums.size();i++) freq[i] = 0; 
        recurPermute(ds, nums, ans, freq); 
        return ans; 
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Freq(26, 0), s2Freq(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            if (s1Freq == s2Freq) {
                return true;
            }
            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i - s1.size()] - 'a']--;
        }
        return s1Freq == s2Freq;
    }
};
