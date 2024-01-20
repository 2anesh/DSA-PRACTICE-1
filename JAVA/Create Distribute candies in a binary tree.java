class Solution
{
    static int ans;
    static int solve(Node root) 
    {
        if(root == null)
            return 0;
        int ln = solve(root.left);
        int rn = solve(root.right);

        ans += Math.abs(ln) + Math.abs(rn);
        return root.data - 1 + ln + rn;
    }
    public static int distributeCandy(Node root) 
    {
        ans = 0;
        solve(root);
        return ans;
    }
}
