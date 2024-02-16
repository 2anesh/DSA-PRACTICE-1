class Solution
{
public:
Node *head=NULL;
Node *tail=head;
void solve(Node *root){
    if(root==NULL)
    return;
    solve(root->left);
     if(tail==NULL){
       head=root;
    }
     if(tail!=NULL){
         tail->right=root;
         tail->left=NULL;
     }
   tail=root;
   solve(root->right);
   tail->right=NULL;
   tail->left=NULL;
}
    Node *flattenBST(Node *root)
    {
        solve(root);
        return head;
    }
};
