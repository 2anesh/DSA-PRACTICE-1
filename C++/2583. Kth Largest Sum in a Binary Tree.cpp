class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum=0;
        vector<long long> ans;
        queue<TreeNode*> q;
        if(!root)   
        return -1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            sum=0;
            while(n--){
                TreeNode * temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end(),greater<long long >());
        if(ans.size()<k)
        return -1;
        else
        return ans[k-1];
    }
};
