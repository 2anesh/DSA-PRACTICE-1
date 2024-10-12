class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        if(arr.size()<2){
            return -1;
        }
        int max=0;
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]+arr[j+1]>max){
                    max=(arr[j]+arr[j+1]);
                }
            }
        return max;
    }
};
