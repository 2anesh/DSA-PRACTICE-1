class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int>res;
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int temp=target-arr[i];
            
            if(res.find(temp)!=res.end()){
                count+=res[temp];
            }
            res[arr[i]]++;
        }
        return count;
    }
};
