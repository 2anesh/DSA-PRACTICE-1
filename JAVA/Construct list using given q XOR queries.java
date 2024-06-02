class Solution {
    public static ArrayList<Integer> constructList(int q, int[][] queries) {
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(0); 
        int cumulativeXOR = 0; 
        for (int i = 0; i < q; i++) {
            if (queries[i][0] == 0) {
                ans.add(queries[i][1] ^ cumulativeXOR);
            } else if (queries[i][0] == 1) {
                cumulativeXOR ^= queries[i][1];
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            ans.set(i, ans.get(i) ^ cumulativeXOR);
        }
        Collections.sort(ans);
        return ans;
    }
}
