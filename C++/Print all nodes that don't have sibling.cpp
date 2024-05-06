void solve(Node* root, vector<int> &a)
{
    if(!root)
        return;
        
    if(root->left == NULL && root->right != NULL)
        a.push_back(root->right->data);
    else if(root->left != NULL && root->right == NULL)
        a.push_back(root->left->data);
        
    solve(root->left,a);
    solve(root->right,a);
}

vector<int> noSibling(Node* node)
{
    vector<int> a;
    solve(node,a);
    if(a.size() == 0)
    {
      a.push_back(-1);
    }
    sort(a.begin(),a.end());
    return a;
}
