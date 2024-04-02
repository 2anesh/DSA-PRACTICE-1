class Solution
{
    public:
    vector<int>res;
    void Inorder(Node *root)
    {
        if(root == NULL)
            return ;
            Inorder(root->left);
            res.push_back(root->data);
            Inorder(root->right);
    }
    int absolute_diff(Node *root)
    {
        Inorder(root);
        int min = INT_MAX;
        for(int i=res.size()-1;i>0;i--)
        {
            if(res[i]-res[i-1] < min)
            min = res[i]-res[i-1];
        }
        return min;
    }
};

