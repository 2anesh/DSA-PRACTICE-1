class Solution {
    
    public boolean countSub(long arr[], long n)
    {
        // Your code goes here
        int j = 0;
        for(int i = 0;i <n  ;i++)
        {
             if(j +i + 2 < n)
              {
         if( arr[i] <arr[i + j +2])
                return false;
              }
              if(j +i + 1 < n)
              {
         if( arr[i] < arr[i + j + 1] )
                
               return false;
              } 
                
                j++;
        }
        
        return true;
    }
}
