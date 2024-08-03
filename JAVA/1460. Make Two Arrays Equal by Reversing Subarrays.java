class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
       Arrays.sort(target);
       Arrays.sort(arr);
       int j=0;
       for(int i=0;i<arr.length;i++)
       {
          if(target[i]==arr[j])
          {
              j++;
              continue;
          }
          else
          {
              return false;
          }
       } 
       return true;
    }
}
