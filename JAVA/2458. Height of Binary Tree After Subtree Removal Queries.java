class Solution {
    int[] height = new int[1000001];
    int[] level = new int[1000001];
    int[] high = new int[1000001];
    int[] secondHigh = new int[1000001];
    public int[] treeQueries(TreeNode root, int[] queries) {
        height(root,0);
        int[] ans = new int[queries.length];
        for(int i=0;i<queries.length;i++)
        {
            int node = queries[i];
            int l = level[node];
            int temp = l+(high[l]==height[node] ? secondHigh[l] : high[l])-1;
            ans[i] = temp;
        }
        return ans;
    }
    private int height(TreeNode root,int l)
    {
        if(root==null)
        return 0;

        level[root.val]=l;
        height[root.val] = Math.max(height(root.left,l+1),height(root.right,l+1))+1;

        if(high[l]<height[root.val])
        {
            secondHigh[l] = high[l];
            high[l]=height[root.val];
        }
        else if(secondHigh[l]<height[root.val])
        {
            secondHigh[l]=height[root.val];
        }
        return height[root.val];
    }
}
