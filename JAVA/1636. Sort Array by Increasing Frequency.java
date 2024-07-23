class Solution {
   public int[] frequencySort(int[] nums) {
   HashMap<Integer,Integer> freq = new HashMap<>() ;
for(int x:nums)
   {
    freq.put(x,freq.getOrDefault(x,0)+1);
}
   PriorityQueue<Map.Entry<Integer,Integer>> maxHeap =
   new PriorityQueue<>((a,b)->(a.getValue()==b.getValue())?(b.getKey()-a.getKey()):(a.getValue()-b.getValue()));

    for(Map.Entry<Integer,Integer> entry: freq.entrySet()){
    maxHeap.add(entry);    
}
    int arr[]= new int[nums.length];
     int ind=0;
  while(!maxHeap.isEmpty())
{
    int mp=maxHeap.poll().getKey();
    int val=freq.get(mp);
    while(val-- !=0)
    {
        arr[ind++]=mp;
    }
  
}
  return arr;
  }
}
