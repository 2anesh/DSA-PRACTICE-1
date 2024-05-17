class Solution {
    public int findPair(int n, int x, int[] arr) {
  HashSet<Integer> hs= new HashSet<>();
  for(int a:arr){
      if(hs.contains(a+x)|| hs.contains(a-x))return 1;
      hs.add(a);
  }
  return -1;
    }
}
