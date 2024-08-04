class Solution {
    public int maxMeetings(int n, int start[], int end[]) {
        if(n==0)
            return 0;
        int arr[][] = new int[n][2];
        for(int i=0 ; i<n ; i++){
            arr[i][0] = start[i];
            arr[i][1] = end[i];
        }
        int ans = 1;
        Arrays.sort(arr,(a, b) -> Integer.compare(a[1],b[1]));
        int sTime = start[0], eTime = arr[0][1];
        for(int i=1 ; i<n ; i++){
            if(eTime < arr[i][0]){
                ans++;
                eTime = arr[i][1];
            }
        }
        return ans;
    }
}
