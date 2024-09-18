class Solution {
    public String largestNumber(int[] nums) {
        ArrayList<String> arr = new ArrayList();
        for(int i=0;i<nums.length;i++)
        {
            arr.add(Integer.toString(nums[i]));
        }
        Collections.sort(arr , (x,y)-> ((y+x).compareTo(x+y)));
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<arr.size();i++)
        {
            sb.append(arr.get(i));
        }
        String ans = sb.toString();
         if(ans.charAt(0) == '0') return "0";
        return ans;
    }
}
