class Solution {
  public:
      int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int felem=-1;
        int selem=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>felem){
                selem=felem;
                felem=arr[i];
            }
            else if(arr[i]>selem && felem!=arr[i]){
                selem=arr[i];
            }
        }
        return selem;
        
    }
};
