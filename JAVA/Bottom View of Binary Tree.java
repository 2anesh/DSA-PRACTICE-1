class Solution {
    class Pair {
        int y; 
        int data; 
        Pair(int y, int data) {
            this.y = y;
            this.data = data;
        }
    }
    public void solve(Node root, int x, int y, TreeMap<Integer, Pair> mp) {
        if (root == null) {
            return;
        }
        if (!mp.containsKey(x) || mp.get(x).y <= y) {
            mp.put(x, new Pair(y, root.data));
        }
        solve(root.left, x - 1, y + 1, mp);
        solve(root.right, x + 1, y + 1, mp);
    }
    public ArrayList<Integer> bottomView(Node root) {
        TreeMap<Integer, Pair> mp = new TreeMap<>();
        ArrayList<Integer> ans = new ArrayList<>();
        solve(root, 0, 0, mp);
        for (Map.Entry<Integer, Pair> entry : mp.entrySet()) {
            ans.add(entry.getValue().data);
        }
        return ans;
    }
}
