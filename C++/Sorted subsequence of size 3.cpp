class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            // cout<<left[i]<<" "<<arr[i]<<" "<<right[i]<<endl;
            if(arr[i]>left[i] && arr[i]<right[i]){
                return {left[i],arr[i],right[i]};
            }
        }
        return {};
    }
};
