class Solution {
  public:
     vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                arr[i]=2*arr[i];
                arr[i+1]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0)
            {
                swap(arr[i],arr[cnt]);
                cnt++;
            }
        }
        return arr;
    }
};
