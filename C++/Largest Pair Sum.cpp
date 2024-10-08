class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int a=arr[0],b=-1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>a){
                b=a;
                a=arr[i];
            }
            else if(arr[i]<a && arr[i]>b){
                b=arr[i];
            }
        }
        return a+b;
    }
};
