class Solution {
    boolean[] visited;
    int nodesCount;
    int neighborsCount;
    HashMap<Integer, Integer> map;
    public void solve(int node, ArrayList<ArrayList<Integer>> adj){
        visited[node] = true;
        ArrayList<Integer> neighbors = adj.get(node);
        neighborsCount = neighbors.size();
        map.put(node, neighborsCount);
        nodesCount++;
        for(Integer neighbor : neighbors){
            if(!visited[neighbor]){
                solve(neighbor, adj);
            }
        }
    }
    public static int findNumberOfGoodComponent(int e, int v, int[][] edges) {
        Solution sol = new Solution();
        sol.visited = new boolean[v+1];
        sol.nodesCount = 0;
        sol.neighborsCount = 0;
        sol.map = new HashMap<>();
        int res = 0;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<=v; i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v1 = edges[i][1];
            adj.get(u).add(v1);
            adj.get(v1).add(u);
        }
        for(int i=1; i<=v; i++){
            if(!sol.visited[i]){
                sol.nodesCount = 0;
                sol.neighborsCount = 0;
                sol.map.clear();
                sol.solve(i, adj);
                int flag = 0;
                for(Integer count : sol.map.values()){
                    if(count != sol.nodesCount - 1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    res++;
            }
        }
        return res;
    }
}
