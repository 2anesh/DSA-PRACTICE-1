class Solution {
    public int rowWithMax1s(int arr[][]) {
        int len=-1;
        int idx=0;
        for(int i=0;i<arr.length;i++){
            int count=0;
            for(int j=0;j<arr[0].length;j++){
                if(arr[i][j]==1)count++;
            }
            if(count!=0){
               if(count>len)idx=i; 
            len=Math.max(count,len);
            }
        }
        if(len==-1)return -1;
        return idx;
    }
} 
