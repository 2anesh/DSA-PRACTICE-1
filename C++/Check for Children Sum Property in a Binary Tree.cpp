class Solution{
    public:
    int isSumProperty(Node *root)
    {
     if(!root){
         return 1;
     }
     if(!root->left && !root->right){
         return 1;
     }
     int left = isSumProperty(root->left);
     int right = isSumProperty(root->right);
     if(left&&right){
         int sum = 0;
         if(root->left){
             sum+=root->left->data;
         }
         if(root->right){
             sum+=root->right->data;
         }
         return sum==root->data;
     }
     return 0;
    }
};
