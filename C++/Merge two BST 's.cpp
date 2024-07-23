class Solution {
  public:
        vector<int> inorder1(Node* root1, vector<int> &res1){
            if(root1==NULL) return res1;
                inorder1(root1->left, res1);
                res1.push_back(root1->data);
                inorder1(root1->right, res1);
            return res1;
        }
        vector<int> merge(vector<int>res1, vector<int>res2, vector<int> & res){
            int m=res1.size();
            int n=res2.size();
            int i=0, j=0;
            while(i<m and j<n){
                if(res1[i]<=res2[j]){
                    res.push_back(res1[i]);
                    i++;
                }else{
                    res.push_back(res2[j]);
                    j++;
                }
            }
            while(i<m){
                res.push_back(res1[i]);
                i++;
            }
            while(j<n){
                res.push_back(res2[j]);
                j++;
            }
            return res;
        }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>res2;
        vector<int>res1;
        vector<int>res;
        inorder1(root1, res1);
        inorder1(root2, res2);
        res=merge(res1, res2, res);
        return res;
    }
};
