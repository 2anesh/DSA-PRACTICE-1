class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector <int> ans;
        vector <int> temp = arr;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            int index = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        return ans;
    }
};
