class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        int i=0;
        int j= n-1;
        int maxi = INT_MIN;
        
        while(i<n)
        {
            if(a[i]>a[j])
            {
                j--;
            }
            else{
                maxi = max(maxi,j-i);
                j = n-1;
                i++;
            }
        }
        return maxi;
    }
};
