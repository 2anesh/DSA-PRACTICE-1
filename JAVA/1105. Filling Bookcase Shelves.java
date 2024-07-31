class Solution {
    int Width;
    int[][] a = new int[1001][1001];
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int remW = shelfWidth;
        for (int[] row : a) 
            Arrays.fill(row, -1); 
        Width = shelfWidth;
        return solve(books, 0, remW,0);
    }
    public int solve(int[][] books,int i,int remW,int maxH)
    {
        if(i>=books.length)
        return maxH;
        if(a[i][remW]!=-1)
        return a[i][remW];
        int bookH = books[i][1];
        int bookW = books[i][0];
        int skip = Integer.MAX_VALUE;
        int keep = Integer.MAX_VALUE;
        if(bookW<=remW)
        {
           keep = solve(books,i+1,remW-bookW,Math.max(maxH,bookH));
        }
         skip  = maxH + solve(books,i+1,Width-bookW,bookH);
        return a[i][remW] = Math.min(keep,skip);
    }
}
