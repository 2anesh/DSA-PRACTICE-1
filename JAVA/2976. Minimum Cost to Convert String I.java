class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int n = source.length();
        int INF = Integer.MAX_VALUE/2; 
        int[][] minCost = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(minCost[i], INF);
            minCost[i][i] = 0;
        }
        for (int i = 0; i < original.length; i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = Math.min(minCost[from][to], cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (minCost[i][k] != INF){ 
                    for (int j = 0; j < 26; j++) {
                        if(minCost[k][j] != INF) {
                            minCost[i][j] = Math.min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                        }
                    }
                }
            }
        }
        long totalCost = 0;
        for (int i = 0; i < n; i++) {
            char s = source.charAt(i);
            char t = target.charAt(i);
            if (s != t) {
                int costToTransform = minCost[s - 'a'][t - 'a'];
                if (costToTransform == INF) {
                    return -1; 
                }
                totalCost += costToTransform;
            }
        }
        return totalCost;        
    }
}
