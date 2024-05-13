class Solution {
    public int matrixScore(int[][] grid) {
        changeRow(grid);
        changeCol(grid);
        return calcScore(grid);
    }
    public void changeRow(int[][] grid)
    {
        for(int i=0;i<grid.length;i++)
        {
            if(grid[i][0]!=1)
            {
                for(int j=0;j<grid[i].length;j++)
                {
                    grid[i][j]^=1;
                }
            }
        }
    }
    public void changeCol(int[][] grid)
    {
        for(int i=1;i<grid[0].length;i++)
        {
            if(checkToChangeCol(i,grid))
            {
                for(int j=0;j<grid.length;j++)
                {
                    grid[j][i]^=1;
                }
            }
        }
    }
    public boolean checkToChangeCol(int x,int[][]grid)
    {
        int one=0;
        int zero=0;
        for(int i=0;i<grid.length;i++)
        {
            if(grid[i][x]==0)
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        return zero>one;
    }
    public int calcScore(int[][]grid)
    {
        int score=0;
        int p=grid[0].length-1;
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                score+=grid[i][j]*(Math.pow(2,p-j));
            }
        }
        return score; 
    }
}
