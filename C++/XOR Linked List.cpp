struct Node *insert(struct Node *head, int data) {
    if ( head == NULL ) return new Node(data);
    else {
        Node *root = new Node(data);
        root->npx = head;
        return root;
    }
}
vector<int> getList(struct Node *head) {
    vector<int> res;
    while ( head ){
        res.push_back(head->data);
        head = head->npx;
    } return res;
}
