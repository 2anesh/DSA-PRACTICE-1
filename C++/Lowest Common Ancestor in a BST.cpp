class Solution {
private:
    void pushing(Node* root, Node* n1, Node* n2, int& ans) {
        if (!root) return;
        if (root->data>n1->data && root->data>n2->data) {
            pushing(root->left,n1,n2,ans);
            return;
        }
        else if (root->data<n1->data && root->data<n2->data) {
            pushing(root->right,n1,n2,ans);
            return;
        }
        ans = min(ans,root->data);
        
    }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        int lowest = INT_MAX;
        pushing(root,n1,n2,lowest);
        Node* ans = new Node(lowest);
        return ans;
        
    }
};
