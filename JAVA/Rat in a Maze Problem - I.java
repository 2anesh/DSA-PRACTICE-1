
class Solution {
    public ArrayList<String> findPath(int[][] mat) {
        int n = mat.length;
        ArrayList<String> ans = new ArrayList<>();
        int visited[][] = new int[n][n];
        for(int[] row : visited){
            Arrays.fill(row, 0);
        }
        if(mat[0][0] == 1) solve(0, 0, n, ans, "", visited, mat);
        return ans;
    }
    void solve(int i, int j, int n, ArrayList<String> ans, String move, int visited[][], int[][] mat){
        if(i == n-1 && j == n-1){
            ans.add(move);
            return;
        }
        if(i+1 < n && visited[i+1][j] != 1 && mat[i+1][j] == 1){
            visited[i][j] = 1;
            solve(i+1, j, n, ans, move+"D", visited, mat);
            visited[i][j] = 0;
        }
        if(j-1 >=0 && visited[i][j-1] != 1 && mat[i][j-1] == 1){
            visited[i][j] = 1;
            solve(i, j-1, n, ans, move+"L", visited, mat);
            visited[i][j] = 0;
        }
        if(j+1 < n && visited[i][j+1] != 1 && mat[i][j+1] == 1){
            visited[i][j] = 1;
            solve(i, j+1, n, ans, move+"R", visited, mat);
            visited[i][j] = 0;
        }
        if(i-1 >=0 && visited[i-1][j] != 1 && mat[i-1][j] == 1){
            visited[i][j] = 1;
            solve(i-1, j, n, ans, move+"U", visited, mat);
            visited[i][j] = 0;
        }
    }
}
