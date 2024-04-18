class Solution
{
    public int[] twoRepeated(int arr[], int n)
    {
       int[] res=new int[2];
       Set<Integer> s= new HashSet<>();
       for(int j=0;j<n+2;j++){
           if(s.contains(arr[j])){
              if(res[0]>0){
                   res[1]=arr[j];
               }
               else{
                   res[0]=arr[j];
               }
           }
           s.add(arr[j]);
       }
      return res;
    }
}
