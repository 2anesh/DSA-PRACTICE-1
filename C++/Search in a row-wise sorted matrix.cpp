class Solution {
  public:
    bool binarySearch(vector<int>mat,int x)
    {
        int left=0;
        int right=mat.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(mat[mid]==x)
            {
                return true;
            }
            else if(mat[mid]>x)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return false;
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            if(binarySearch(mat[i],x))
            {
                return true;
            }
        }
        return false;
    }
};
