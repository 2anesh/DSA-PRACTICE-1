class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);        
        int num = 0, curr_sum = 0;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum += nums[i];
            if(curr_sum == k)num++;
            if(mp.find(curr_sum - k) != mp.end())
            {
                num += mp[curr_sum - k];
            }
            mp[curr_sum]++;
        }
        return num;
    }    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int total=0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){			
            vector<int> sum(m, 0);
            for(int j=i; j<n; j++){
                for(int k=0; k<m; k++){
                    sum[k] += mat[j][k];
                }
                total += subarraySum(sum, target);
            }
        }       
    return total;
        
    }
};
