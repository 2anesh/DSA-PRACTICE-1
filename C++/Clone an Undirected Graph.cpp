class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* n = new Node(node->val);
        mp[node] = n;
        for(auto it : node->neighbors){
            if(mp.find(it) == mp.end())
                n->neighbors.push_back(cloneGraph(it));
            else
                n->neighbors.push_back(mp[it]);
        }
        return n;
    }
};
