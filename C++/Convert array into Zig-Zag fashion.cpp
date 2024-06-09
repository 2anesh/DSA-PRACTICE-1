class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
         if(arr[0]>arr[1]){
            swap(arr[0],arr[1]);
        }
        for(int i=1;i<n-1;i++){
            if(i%2!=0){
                if(arr[i]<arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }else if(i%2==0){
                if(arr[i]>arr[i+1]){
                      swap(arr[i],arr[i+1]);
                }
            }
        }
   return;
    }
};
