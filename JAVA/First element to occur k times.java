class Solution
{
    public int firstElementKTime(int n, int k, int[] arr) { 
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<n; i++){
            if(map.containsKey(arr[i])){
                map.put(arr[i], map.get(arr[i]) + 1);
                
                if(map.get(arr[i]) >= k){
                    return arr[i];
                }
            } else {
                map.put(arr[i], 1);
            }
        }
         return -1;
    } 
}
