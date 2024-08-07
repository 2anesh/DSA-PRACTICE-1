class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        while(i<n && j<m)
        {
            if (k==1) return arr1[i]<arr2[j]?arr1[i]:arr2[j];
            if(arr1[i]<arr2[j]) i++;
            else j++;
            k--;
        }
        while(i<n)
        {
            if (k==1) return arr1[i];
            i++;
            k--;
        }
        while(j<m)
        {
            if (k==1) return arr2[j];
            j++;
            k--;
        }
       return -1;
    }
};
