class Solution {
  public:
    int h(Node* n){return 1 + max(n->left?h(n->left):0,n->right?h(n->right):0);}
    int height(Node* node) {return node?(h(node) - 1):0;}
};
