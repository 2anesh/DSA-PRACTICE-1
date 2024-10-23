class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL)
            return {};
        if(root->left == NULL && root->right == NULL){
            root->val = 0;
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        unordered_map<TreeNode*, TreeNode*> m; 
        unordered_map<TreeNode*, int> m2; 
        while(!q.empty()){
            int n = q.size();
            m.clear();
            int sum = 0;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                m2[curr] = 0;
                if(curr->left != NULL){
                    q.push(curr->left);
                    m[curr->left] = curr;
                    sum += curr->left->val;
                    m2[curr] += curr->left->val;
                }  
                if(curr->right != NULL){
                    q.push(curr->right);
                    m[curr->right] = curr;
                    sum += curr->right->val;
                    m2[curr] += curr->right->val;
                }  

            }
            for(auto& it : m){
                TreeNode* child = it.first;
                TreeNode* parent = it.second;
                child->val = sum - m2[parent];
            }
        }
        return root;        
    }
};
