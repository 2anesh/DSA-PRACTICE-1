class Solution
{
    public:
    vector<Node*> leaf;
    unordered_map<Node*,int> vis;
    void parenting(Node* root,unordered_map<Node*,Node*> &parent){
        if(root->left){
            parent[root->left] = root;
            parenting(root->left,parent);
        }
        if(root->right){
            parent[root->right] = root;
            parenting(root->right,parent);
        }
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root);
        }
    }
    int check(Node* leaf,unordered_map<Node*,Node*> &parent,int k){
        if(leaf == NULL){
            return 0;
        }
        if(k == 0 && vis[leaf] ==0 ){
            vis[leaf]=1;
            return 1;
        }
        if(k<0){
            return 0;
        }
        k--;
        check(parent[leaf],parent,k);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
        unordered_map<Node*,Node*> parent;
        parent[root] = NULL;
        parenting(root,parent);
        int result = 0;
        for(auto j: leaf){
            result += check(j,parent,k);
        }
        return result;
    }
};
