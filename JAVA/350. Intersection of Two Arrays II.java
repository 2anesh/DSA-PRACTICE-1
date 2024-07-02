class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
    HashMap<Integer,Integer> map = new HashMap<>();
    ArrayList<Integer> l = new ArrayList<>();
    int n = nums1.length;
    int m = nums2.length;
    for(int i = 0;i<n;i++){
        map.put(nums1[i],map.getOrDefault(nums1[i],0)+1);
    }
    for(int i = 0;i<m;i++){
        if(map.getOrDefault(nums2[i],0)>0){
            l.add(nums2[i]);
            map.put(nums2[i],map.get(nums2[i])-1);
        }
    }
    int arr[] = new int[l.size()];
    for(int i = 0;i<l.size();i++){
        arr[i] = l.get(i);
    }
      return arr;
    }
}
