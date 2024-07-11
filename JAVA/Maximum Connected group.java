class Solution {
    private int[][] component;
    private int[] componentSize;
    private int componentId = 1;
    private final int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int n;
    public int MaxConnection(int[][] grid) {
        n = grid.length;
        component = new int[n][n];
        componentSize = new int[n * n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && component[i][j] == 0) {
                    dfs(grid, i, j, componentId++);
                }
            }
        }
        int maxConnection = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> neighborComponents = new HashSet<>();
                    for (int[] direction : directions) {
                        int ni = i + direction[0];
                        int nj = j + direction[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && component[ni][nj] > 0) {
                            neighborComponents.add(component[ni][nj]);
                        }
                    }
                    int possibleConnection = 1;
                    for (int compId : neighborComponents) {
                        possibleConnection += componentSize[compId];
                    }
                    maxConnection = Math.max(maxConnection, possibleConnection);
                }
            }
        }
        for (int size : componentSize) {
            maxConnection = Math.max(maxConnection, size);
        }
        return maxConnection;
    }
    private void dfs(int[][] grid, int x, int y, int id) {
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{x, y});
        component[x][y] = id;
        int size = 0;
        while (!stack.isEmpty()) {
            int[] cell = stack.pop();
            int i = cell[0], j = cell[1];
            size++;
            for (int[] direction : directions) {
                int ni = i + direction[0];
                int nj = j + direction[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1 && component[ni][nj] == 0) {
                    component[ni][nj] = id;
                    stack.push(new int[]{ni, nj});
                }
            }
        }
        componentSize[id] = size;
    }
}
