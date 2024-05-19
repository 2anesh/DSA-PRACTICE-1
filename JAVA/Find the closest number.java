class Solution {
    public static int findClosest(int n, int k, int[] arr) {
         int left=0;
        int right=n-1;
        while(left<=right) {
            int mid=(left+right)>>1;
            if(k<arr[mid]) {
                right=mid-1;
            }else {
                left=mid+1;
            }
        }
        if(left==arr.length)return arr[right];
        if(right<0)return arr[left];
        
        int ans=arr[left];
        int diff=Math.abs(k-ans);
        if(diff>Math.abs(k-arr[right])) ans=arr[right];
        return ans;
    }
}
        
