class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        UFDS ufds = new UFDS(n);
        for (int[] edge : edges)
        {
            ufds.merge(edge[0], edge[1]);
        }
        int rootSource = ufds.find(source);
        int rootDestination = ufds.find(destination);
        boolean equal = (rootSource == rootDestination);
        return equal;
    }
    static class UFDS
    {
        int[] p;
        public UFDS(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }
        public int find(int x) {
            if (x == p[x]) {
                return x;
            }
            return p[x] = find(p[x]);
        }
        public void merge(int x, int y) {
            int lx = find(x);
            int ly = find(y);
            if (lx != ly)
            {
                p[ly] = lx;
            }
        }
    }
}
