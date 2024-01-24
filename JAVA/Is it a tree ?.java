class Solution {
    
    private boolean isCycle(List<List<Integer>> adj, Set<Integer> vis, int n, int m, int node, int par){
        vis.add(node);
        for (int newNode : adj.get(node)){
            if (!vis.contains(newNode)){
                if (!isCycle(adj, vis, n, m, newNode, node)) return false;
            }
            else if (newNode != par) return false;
        }
        return true;
    }
    public boolean isTree(int n, int m, ArrayList<ArrayList<Integer>> edges) 
    {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int idx = 0; idx < m; idx++){
            adj.get(edges.get(idx).get(0)).add(edges.get(idx).get(1));
            adj.get(edges.get(idx).get(1)).add(edges.get(idx).get(0));
        }
        Set<Integer> vis = new HashSet<>();
        boolean res = isCycle(adj,vis,n,m,0,-1);
        if (vis.size() != n) return false;
        return res;
    }
}
