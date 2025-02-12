class Solution {
  public:
    void inorder(Node* root, vector<int>& ls) {
        if(root != nullptr) {
            inorder(root->left, ls);
            ls.push_back(root->data);
            inorder(root->right, ls);
        }
    }
    int kthSmallest(Node *root, int k) {
        vector<int> ls;
        inorder(root, ls);
        if (k > ls.size()) return -1; 
        priority_queue<int> maxh; // Using priority_queue
        for(int i = 0; i < ls.size(); ++i) {
            maxh.push(ls[i]);
            if(maxh.size() > k) maxh.pop();
        }
        return maxh.top();
    }
};
