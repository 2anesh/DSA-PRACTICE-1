class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) {
        long long sum = 0;
        vector<int> v;
        for(auto it: arr){
            sum += it;
        }
        sum/=3;
        int i = 0, j = 0;
        long long s = 0;
        while(i < arr.size()){
            s += arr[i];
            if(s == sum){
                v.push_back(i);
                s = 0;
                if(v.size() == 2){
                    return v;
                }
            }
            i++;
        }
        return {-1,-1};
    }
};

