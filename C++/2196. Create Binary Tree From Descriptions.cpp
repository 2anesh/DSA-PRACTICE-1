class Solution {
public:
    void formBinaryTree(TreeNode* root, unordered_map<int, vector<pair<int,pair<int,int>>>> &adj){
        if(adj.find(root->val)==adj.end() || adj[root->val].size()==0) {
            root->left=NULL;
            root->right=NULL;
            return;
        }
        for(auto it:adj[root->val]){
            if(it.second.second==false){
                if(it.second.first==1){
                    root->left=new TreeNode(it.first);
                    it.second.second=true;
                    formBinaryTree(root->left, adj);
                }
                if(it.second.first==0){
                    root->right=new TreeNode(it.first);
                    it.second.second=true;
                    formBinaryTree(root->right, adj);
                }
            }
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int,pair<int,int>>>> adj;
        unordered_map<int,int> indegrees;
        TreeNode* root = new TreeNode();
        for(int i=0;i<descriptions.size();i++){
            adj[descriptions[i][0]].push_back({descriptions[i][1], {descriptions[i][2], false}});
            indegrees[descriptions[i][1]]++;
        }
        for(auto it: adj){
            if(indegrees.find(it.first)==indegrees.end()){
                root->val=it.first;
            }
        }
        formBinaryTree(root, adj);
        return root;
    }
};
