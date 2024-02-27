class Solution {
public:
int height ( TreeNode* root ) {
    if ( root == NULL ) {
        return 0 ;
    }
    int leftheight = height (root -> left ) ;
    int rightheight = height (root -> right );
    int ans = max ( leftheight, rightheight) + 1 ;
    return ans ;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL ){
            return 0 ;
        }
        int op1 = diameterOfBinaryTree(root -> left ) ;
        int op2 = diameterOfBinaryTree(root -> right ) ;
        int op3 = height(root -> left ) + height(root -> right  ) ;
        int ans1 = max (op1 , max (op2 , op3) ) ;

        return ans1  ; 
    }
};
