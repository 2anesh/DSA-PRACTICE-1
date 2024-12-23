class Solution {
public:
int minimumOperations(TreeNode* root) {
        int result = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!empty(q)) {
            
              int x=q.size();
            while (x-->0) {
                 TreeNode*front=q.front();
                 q.pop();
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            vector<pair<int,int>>p;
            queue<TreeNode*>t;
            int i=0;
            while(!q.empty()){
                TreeNode*f=q.front();
                t.push(f);
                q.pop();

                p.push_back({f->val,i});
                i++;
            }
            sort(p.begin(),p.end());

            for (int i = 0; i < size(p); ++i) {
                if(p[i].second==i) continue;
                else{
                    result++;
                    swap(p[i],p[p[i].second]);
                    i--;
                }
            }
           q=t; 
        }
        return result;
    }
};
