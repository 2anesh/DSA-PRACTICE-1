class Solution
{
    public:
    vector<vector<int>> result;
    vector<int> ans;
    void pathfinder(Node *root,int curr_sum,int sum)
    {
        if(root==NULL)
            return;
        curr_sum+=root->key;
        ans.push_back(root->key);
        if(curr_sum==sum)
            result.push_back(ans);
        pathfinder(root->left,curr_sum,sum);
        pathfinder(root->right,curr_sum,sum);
        ans.pop_back();
        return;
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        pathfinder(root,0,sum);
        return result;
    }
};
