class Solution {
    public static int longestSubseq(int n, int[] a) {
        return solve(a,0,n,-1);
    }
    public static int solve(int arr[],int idx ,int n,int prev){
        if(idx >= n){
            return 0;
        }
        int max = 0;
        for(int x = idx;x<n;x++){
            int diff = Math.abs(prev-arr[x]);
            if(diff == 1 || prev == -1){
                max = Math.max(max,1+solve(arr,x+1,n,arr[x]));
            }
            
        }
        return max;
    }
}
