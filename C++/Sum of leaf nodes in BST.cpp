class Solution
{
    public:
        void traverse(Node *root,int&sum){
            if(!root){
                return;
            }
            if(!root->left && !root->right){
                sum+=root->data;
                return;
            }
            traverse(root->left,sum);
            traverse(root->right,sum);
        }
        int sumOfLeafNodes(Node *root ){
             int sum = 0;
             traverse(root,sum);
             return sum;
        }
};
