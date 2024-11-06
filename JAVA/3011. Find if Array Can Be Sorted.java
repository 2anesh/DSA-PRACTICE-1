
class Solution {
    public boolean canSortArray(int[] nums) {
        int n=nums.length;
        boolean flag=true;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=false;
            }
        }
        if(flag){
            return true;
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if((nums[j]>nums[j+1]) && (getBits(nums[j])==getBits(nums[j+1]))){
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
        
    }
    
    public int getBits(int n){
        int bitCount=0;
        
        while(n!=0){
            bitCount+=(n&1);
            n=n>>1;
        }
        return bitCount;
    }
}
