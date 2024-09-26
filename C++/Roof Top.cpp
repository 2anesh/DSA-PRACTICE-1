class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int curr=0,max_curr=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                curr++;
            }
           else{
               if(curr>max_curr){
                   max_curr=curr;
               }
               curr=0;
           }
        }
        if(curr>max_curr){
                   max_curr=curr;
               }
        return max_curr;
    }
};
