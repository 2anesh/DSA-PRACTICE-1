class Solution {
    private List<List<Integer>> adjList;
    private boolean[] visited;
    private int[] subSize;
    private int cnt;
    private void dfs(int node) {
        visited[node] = true;
        subSize[node] = 1;
        for (int neighbor:adjList.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor);
                subSize[node] += subSize[neighbor];
                if (subSize[neighbor] % 2 == 0) {
                    cnt++;
                }
            }
        }
    }
    public int minimumEdgeRemove(int n, int[][] edges) {
        adjList = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }
        visited = new boolean[n+1];
        subSize = new int[n+1];
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        return cnt;
    }
}
