class Solution
{
    Node *build(int &postIdx, int inStart, int inEnd, int len, int in[], int post[])
    {
        if (postIdx < 0) 
            return NULL;
        if (inStart > inEnd)
            return NULL;
        int idx = inStart;
        for (; idx <= inEnd; ++idx)
            if (post[postIdx] == in[idx])
                break;
        Node *root = new Node(post[postIdx--]);
        root->right = build(postIdx, idx + 1, inEnd, len, in, post);
        root->left = build(postIdx, inStart, idx - 1, len, in, post);
        return root;
    }
    public:
    Node *buildTree(int in[], int post[], int n) 
    {
        int postIdx = n - 1;
        return build(postIdx, 0, n - 1, n, in, post);
    }
};
