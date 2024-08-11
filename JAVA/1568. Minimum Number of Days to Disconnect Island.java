class Solution {   
    public void dfs(int r, int c, int[][] grid, 
                    Set<Pair<Integer, Integer>> visit) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length 
            || grid[r][c] == 0 || visit.contains(new Pair(r, c))) return;
        visit.add(new Pair(r, c));
        dfs(r + 1, c, grid, visit);
        dfs(r - 1, c, grid, visit);
        dfs(r, c + 1, grid, visit);
        dfs(r, c - 1, grid, visit);
    }
    public int countIsland(int[][] grid) {
        Set<Pair<Integer, Integer>> visit = new HashSet<>();
        int count = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1 && 
                    !visit.contains(new Pair(r, c))){
                        count += 1;
                        dfs(r, c, grid, visit);
                }
            }
        }
        return count;
    }
    public int minDays(int[][] grid) {        
        if (countIsland(grid) != 1) return 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (countIsland(grid) != 1) return 1;
                    grid[r][c] = 1;
                }
            }
        }
        return 2;
    }
}
