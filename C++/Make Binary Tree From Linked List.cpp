void convert(Node *head, TreeNode *&root) {
    vector<int> list;
    Node* ptr = head;
    while(ptr != NULL) {
        list.push_back(ptr -> data);
        ptr = ptr -> next;
    }
    queue<TreeNode*> q;
    root = new TreeNode(list[0]);
    q.push(root);
    int itr = 0;
    while(!q.empty()) {
        int n = q.size();
        for(int i=0; i<n; i++) {
            auto node = q.front();
            q.pop();
            if((2*itr+1) < list.size()) {
                node -> left = new TreeNode(list[2*itr+1]);
                q.push(node -> left);
            }
            if((2*itr+2) < list.size()) {
                node -> right = new TreeNode(list[2*itr+2]);
                q.push(node -> right);
            }
            itr++;
        }
    }
    return;
}
