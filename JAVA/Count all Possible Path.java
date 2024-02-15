class Solution
{
    public int isPossible(int[][] paths)
    {
        for(int i=0;i<paths.length;i++){
            int su=0;
            for(int j=0;j<paths[i].length;j++){
                if(paths[i][j]==1)su++;
            }
            if(su%2==1)return 0;
        }
        return 1;
    }
}
