class Solution {
    int minCount=Integer.MAX_VALUE;
    public int numSquares(int n) 
    {        
        int end=1;    
        while((end+1)*(end+1)<=n)
            end++;
        int arr[] = new int[end+1];
        for(int i=1;i<=end;i++)
        {
            arr[i]=i*i;
        }        
        return getCount(arr, 0, n, end);        
    }    
    public int getCount(int arr[], int count, int n, int index)
    {
        if(n==0)
        {            
            return count;
        }        
        if(index<=0)
        {
            return Integer.MAX_VALUE;
        }        
        int x = arr[index];
        int currCount = n/x;
        int remNum = n%x;        
        if(x<=n)
            return Math.min(getCount(arr, count+currCount, remNum, index-1), getCount(arr, count, n, index-1));        
        return getCount(arr, count, n, index-1);
    }
    public void getCount2(int arr[], int count, int n, int index)
    {
        if(n==0)
        {
            minCount=Math.min(minCount, count);
            return;
        }        
        if(index<=0)
        {
            return;
        }        
        int x = arr[index];
        int currCount = n/x;
        int remNum = n%x;        
        if(x<=n)
            getCount(arr, count+currCount, remNum, index-1);
        getCount(arr, count, n, index-1);
    }        
}
