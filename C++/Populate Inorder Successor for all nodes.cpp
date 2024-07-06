class Solution {
  public:
    void inorder(Node* node, stack<Node*> &st)
    {
        if(node->left)
        {
            inorder(node->left, st);
        }
        if(st.empty())
        {
            st.push(node);
        }
        else
        {
            Node* temp = st.top();
            temp->next = node;
            st.pop();
            st.push(node);
        }
        if(node->right)
        {
            inorder(node->right, st);
        }
    }
    void populateNext(Node *root) 
    {
        stack<Node*> st;
        inorder(root, st);
    }
};
