class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int ans = 0;
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);
        int sum = 0;
        int rem = 0;
        for (int i = 0; i < nums.length; i++) {
            sum+=nums[i];
            rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            if(hm.containsKey(rem)){
                ans += hm.get(rem);
                hm.put(rem,hm.get(rem) + 1);
            }else {
                hm.put(rem,1);
            }
        }
        return ans;
    }
}
