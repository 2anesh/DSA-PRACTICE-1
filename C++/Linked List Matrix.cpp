class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        Node *ptr = nullptr;
        Node *head = nullptr;
        vector<vector<Node*>> nodeStore(n+1,vector<Node*>(n+1,nullptr));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                Node *newNode = new Node(mat[i][j]);
                nodeStore[i][j]=newNode;
            }
        }
        head = nodeStore[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ptr = nodeStore[i][j];
                ptr->right = nodeStore[i][j+1];
                ptr->down = nodeStore[i+1][j];
            }
        }
        return head;
    }
};
