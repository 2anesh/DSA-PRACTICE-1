class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        Map<String,Integer> memo = new HashMap<>();
        int[][] dp = new int[n1+1][n2+1];
        return recursion (text1, text2, n1, n2, dp,memo);        
    }
    public int recursion(String text1, String text2,int n1, int n2, int[][] dp,Map<String,Integer> memo){
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        String key = n1 + "-" +n2;
        if(memo.containsKey(key)){
            return memo.get(key);
        }        
        if(text1.charAt(n1-1) == text2.charAt(n2 - 1)){
            dp[n1][n2] = 1+recursion (text1, text2, n1-1, n2-1, dp,memo);
        }
        else{            
            dp[n1][n2] = Math.max(recursion (text1, text2, n1, n2-1, dp,memo),recursion (text1, text2, n1-1, n2, dp,memo));
        }
        memo.put(key,dp[n1][n2]);
        return dp[n1][n2];
    }
}
