class Solution {
  public:
   bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector <int> V(1e5+1, 0);
        for(auto& e: arr) V[e]++;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = arr[i] + arr[j];
                if(sum <= 1e5 && V[sum]) return true;
            }
        }
        return false;
    }
};
