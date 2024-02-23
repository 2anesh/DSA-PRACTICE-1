class Solution {
    int[][] memo;
    int src;
    HashMap<Integer, List<int[]>> inDegree;
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        this.src = src;
        inDegree = new HashMap<>();
        K++;
        memo = new int[n][K + 1];
        for (int i = 0; i < n; i++){
            Arrays.fill(memo[i], -666);
        }
        for (int[] flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            inDegree.putIfAbsent(to, new LinkedList<int[]>());
            inDegree.get(to).add(new int[] {from, price});
        }
        return dp(dst, K);
    }
    public int dp(int s, int k){
        int res = Integer.MAX_VALUE;
        if (s == src) return 0;
        if (k == 0) return -1;
        if (memo[s][k] != -666) return memo[s][k];
        if (inDegree.containsKey(s)){
            for (int[] pre : inDegree.get(s)){
                if (dp(pre[0], k - 1) != -1) res = Math.min(res, dp(pre[0], k - 1) + pre[1]);
            }
        }
        memo[s][k] = res == Integer.MAX_VALUE? -1 : res;
        return memo[s][k];
    }
}
