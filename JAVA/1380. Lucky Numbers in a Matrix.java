class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
    int n = matrix.length;
    int m = matrix[0].length;
    List<Integer> res=new ArrayList<>();
    for(int i=0;i<n;i++){
        int num=Integer.MAX_VALUE;
        int index=-1;
        for(int j=0;j<m;j++){
            if(matrix[i][j]<num){
                num=matrix[i][j];
                index=j;
            }
        }
        boolean b=true;
        for(int rw=0;rw<n;rw++){
            if(matrix[rw][index]>num)
            b=false;
        }
        if(b) res.add(num);
    } 
    return res; 
    }
}
