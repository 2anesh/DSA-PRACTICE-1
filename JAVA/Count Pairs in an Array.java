class Solution {  
    static int count = 0;
    static int countPairs(int arr[], int n) 
    {
        count  = 0;
         for(int i = 0 ;i < n;i++)
         {
             arr[i] = arr[i] * i;
         }
         mergesort(arr,0,n -1);
         return count ;
    }
  public static void mergesort(int arr[],int l,int h)
{
    if(l < h)
    {
        int mid = l  + (h - l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid + 1,h);
        merge(arr,l,mid,h);
    }
    return; 
}
    public static void merge(int arr[],int l, int mid,int h)
    {
        int n1 = mid - l + 1;
        int n2 = h - mid;
        int temp1 [] = new int[n1];
        int temp2 [] = new int[n2];
        
        for(int m =0 ;m < n1;m++)
        {
            temp1[m] = arr[l + m];
        }
        for(int s = 0; s< n2;s++)
        {
            temp2[s] = arr[mid + 1 + s];
        }
        int i = 0;int j = 0;int k = l;
        
        while(i < n1 && j < n2)
        {
            if(temp1[i] <= temp2[j])
            {
                arr[k] = temp1[i];
                ++i;
            }
            else
            {
                count += n1 - i ;
                arr[k] = temp2[j];
                ++j;
            }
            ++k;
        }
        while(i < n1)
        {
            arr[k] = temp1[i];
            ++i;
            ++k;
        }
        while(j < n2)
        {
            arr[k] = temp2[j];
            ++k;
            ++j;
        }
    }
}
