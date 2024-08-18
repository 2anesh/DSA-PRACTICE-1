class Solution {
  public:
    bool canSplit(vector<int>& arr) {
      int n=arr.size();
      int i=0;
      int j=n-1;
      int leftsum=arr[0];
      int rightsum=arr[n-1];
      while(i<j){
          if(leftsum==rightsum && i+1==j){
              return true;
          }
          else if(leftsum>rightsum){
              j--;
              rightsum+=arr[j];
          }
          else{
                 i++;
             leftsum+=arr[i];
          }
      }
      return false;
    }
};
