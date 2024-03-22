class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        queue<Node*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int n=q.size();class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        queue<Node*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                Node *j=q.front();
                while(j){
                    q.push(j->left);
                    sum+=j->data;
                    j=j->right;
                }
                q.pop();
            }
            v.push_back(sum);
        }
        v.pop_back();
        return v;
    }
};
            int sum=0;
            while(n--){
                Node *j=q.front();
                while(j){
                    q.push(j->left);
                    sum+=j->data;
                    j=j->right;
                }
                q.pop();
            }
            v.push_back(sum);
        }
        v.pop_back();
        return v;
    }
};
