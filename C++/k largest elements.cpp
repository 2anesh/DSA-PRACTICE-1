class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1 ; i>=0 ; i--){
            ans.push_back(arr[i]);
            k--;
            if(k==0)
            break;
        }
        return ans;
    }
};
