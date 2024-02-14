class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] arr=new int[nums.length];
        int a=0;
        int b=1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                arr[a++]=nums[i];
                a++;
            }
            else{
                arr[b++]=nums[i];
                b++;
            }
        }
        return arr;       
    }
}
