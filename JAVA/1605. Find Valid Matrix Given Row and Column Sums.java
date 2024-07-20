class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int N=rowSum.length;
        int M=colSum.length;
        int currRowSum[]=new int[N];
        int currColSum[]=new int[M];
        int origMat[][]=new int[N][M];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                origMat[i][j]=Math.min(rowSum[i] - currRowSum[i],
                    colSum[j] - currColSum[j]);
                currRowSum[i] += origMat[i][j];
                currColSum[j] += origMat[i][j];
            }           
        }
        return origMat;
    }    
}
