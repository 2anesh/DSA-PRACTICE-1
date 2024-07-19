class Solution {
    int[] constructLowerArray(int[] arr) {
        int res[]=new int[arr.length];
        for(int i=0;i<arr.length-1;i++){
            int c=0;
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]>arr[j]){
                    c++;
                }
            }
            res[i]=c;
        }
        return res;
    }
}
