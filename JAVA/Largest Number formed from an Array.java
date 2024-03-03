class Solution {
    String printLargest(int n, String[] arr) {
        Arrays.sort(arr, new Comparator<String>(){
            @Override
            public int compare(String x, String y){
                String xy=x+y;
                String yx= y+x;
                return yx.compareTo(xy);
            }
        });
        String ans="";
        for(int u=0;u<n;u++){
            ans+=arr[u];
        }
        return ans;
    }
}
