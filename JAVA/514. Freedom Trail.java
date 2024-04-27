class Solution {
    int[][] memo;
    HashMap<Character, List<Integer>> charToIndex = new HashMap<>();
    public int findRotateSteps(String ring, String key) {
        int m = ring.length(), n = key.length();
        memo = new int[m][n];
        for (int i = 0; i < m; i++){
            charToIndex.putIfAbsent(ring.charAt(i), new LinkedList<>());
            charToIndex.get(ring.charAt(i)).add(i);
            Arrays.fill(memo[i], -6);
        }
        return dp(ring, key, 0, 0);
    }
    public int dp(String ring, String key, int i, int j){
        int m = ring.length(), n = key.length();
        if (j == n) return 0;
        if (memo[i][j] != -6) return memo[i][j];
        int res = Integer.MAX_VALUE;       
        for (int k : charToIndex.get(key.charAt(j))){
            int delta = Math.abs(k - i);
            delta = Math.min(delta, m - delta);
            int subProblem = delta + 1 + dp(ring, key, k, j + 1);
            res = Math.min(res, subProblem);
        }
        memo[i][j] = res;
        return res;
    }
}
