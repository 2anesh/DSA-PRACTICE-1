class Solution
{    
public:
    int ans = 0, maxPath = 0;
    
    void solve(Node* root, vector<int>& temp, int sum) {
        if(!root) {
            int n = (int)temp.size();
            
            if(maxPath < n) {
                maxPath = n;
                ans = sum;
            }
            if(maxPath == n) {
               if(sum>ans) ans = sum;
            }
            return;
        }
        temp.push_back(root->data);
        sum += root->data;
        solve(root->left, temp, sum);
        solve(root->right, temp, sum);
        sum -= root->data;
        temp.pop_back();
        return;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        vector<int> temp;
        solve(root, temp, 0);
        return ans;
    }
};
