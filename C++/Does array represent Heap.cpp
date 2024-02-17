class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {   
        for(int i=0;i<n;i++)
        {
            int l=2*i + 1;
            int r=2*i + 2;
            if(l<n)
            {
                if(arr[l]>arr[i])
                    return 0;
            }
            if(r<n)
            {
                if(arr[r]>arr[i])
                    return 0;
            }
        }
        return 1;
    }
};
