class Solution {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        int N=arr1.length,M=arr2.length;
        int k=(N+M-1)/2,max=Integer.MAX_VALUE;
        int l=0,r=Math.min(N-1,k),cntr1=0;
        while(l<=r){
            int m=(l+r)/2;
            int cntr2=binSearchLowerEleCnt(arr2,arr1[m]);
            if(m+cntr2==k){
                int sum=arr1[m];
                sum+=Math.min((cntr2==M)?max:arr2[cntr2],
                      (m+1==N)?max:arr1[m+1]);
                return sum;
            }else if(m+cntr2<k){
                cntr1=m+1;
                l=m+1;
            }else
                r=m-1;
        }
        int sum=arr2[k-cntr1];
        sum+=Math.min((cntr1==N)?max:arr1[cntr1],
                      (k-cntr1+1==M)?max:arr2[k-cntr1+1]);
        return sum;
    }
    int binSearchLowerEleCnt(int[] arr,int find){
        int cnt=arr.length;
        int l=0;
        int r=arr.length-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]>=find){
                cnt=m;
                r=m-1;
            }else
                l=m+1;
        }
        return cnt;
    }
}
