class Solution{
    private:
    Node * fillParent(unordered_map<Node *,Node *> &parent,Node *root,int a){
        Node * start = NULL;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node * node = q.front();
            q.pop();
            if(node->data == a) start = node;
            if(node ->left){
                parent[node ->left] = node;
                q.push(node ->left);
            }
            if(node ->right){
                parent[node ->right] = node;
                q.push(node ->right);
            }
        }
        return start;
    }
    public:
    int findDist(Node* root, int a, int b) {
        unordered_map<Node *,Node *> parent;
        Node * start = fillParent(parent,root,a);
        queue<Node * >q;
        set<Node*>vis;
        vis.insert(start);
        q.push(start);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            int flage = false; 
            for(int i=0; i<sz; i++){
                Node * node = q.front();
                q.pop();
                if(node->data == b){
                    flage = true;
                    break;
                }
                if(node->left && vis.find(node->left) == vis.end()){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right) == vis.end()){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(parent[node] && vis.find(parent[node]) == vis.end()){
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            if(flage) break;
            level++;
        }
        return level;
    }
};
