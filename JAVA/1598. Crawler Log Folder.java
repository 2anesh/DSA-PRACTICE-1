class Solution {
    public int minOperations(String[] logs) {
        int res = 0;
        for (String log: logs) {
            res += add(log,res);
        }
        return res;
    }
    private int add(String log, int res) {
        return log.charAt(1) == '.' ? res == 0 ? 0 : -1 : log.charAt(0) == '.' ? 0 : 1;
    }
}
