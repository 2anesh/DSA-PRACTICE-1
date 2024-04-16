class Solution {
    public static int minimizeDifference(int n, int k, int[] arr) {
     Node[]nodes = new Node[n];
     int min = Integer.MAX_VALUE,max = 0;
     for(int i=0;i<n;i++){
         min = Math.min(min,arr[i]);
         max = Math.max(max,arr[i]);
         nodes[i] = new Node(max,min,0,Integer.MAX_VALUE);
     }
     min = Integer.MAX_VALUE;max = 0;
     for(int i=n-1;i>=0;i--){
         min = Math.min(min,arr[i]);
         max = Math.max(max,arr[i]);
         Node node = nodes[i];
         node.nextLarge = max;
         node.nextMin = min;
     }
     int i=0,j=k-1,ans = Integer.MAX_VALUE;
     while(j<n){
         int a=0,b=0,c=Integer.MAX_VALUE,d=Integer.MAX_VALUE;
         if(i>0){
             a = nodes[i-1].prevLarge;
             c = nodes[i-1].prevMin;
         }
         if(j<n-1){
             b = nodes[j+1].nextLarge;
             d = nodes[j+1].nextMin;
         }
         max = Math.max(a,b);
         min = Math.min(c,d);
         ans = Math.min(ans,max-min);
         j++;
         i++;
     }
     return ans;
    }
}
class Node{
    int prevLarge,nextLarge,prevMin,nextMin;
    public Node(int pl,int pm,int nl, int nm){
        prevLarge = pl;
        prevMin = pm;
        nextLarge = nl;
        nextMin = nm;
    }
}

