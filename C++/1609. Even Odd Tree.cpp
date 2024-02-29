class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push(root) ;
        int level = 0 ;
        while(!q.empty()) {
            vector<int> temp ;
            int size = q.size() ;
            for(int i=0 ; i<size ; i++) {
                auto node = q.front() ;
                q.pop() ;
                if(node->left != NULL) q.push(node->left) ;
                if(node->right != NULL) q.push(node->right) ;
                temp.push_back(node->val) ;
            }
            if(level % 2 == 0) {                  
                for(int i=0 ; i<temp.size() ; i++) {
                    if(temp[i] % 2 == 0) return false ; 
                }
                for(int i=0 ; i<temp.size()-1 ; i++) {
                    if(temp[i] >= temp[i+1]) return false ;
                }
            }
            else{               
                for(int i=0 ; i<temp.size() ; i++) {
                    if(temp[i] % 2 != 0) return false ;
                }
                for(int i=0 ; i<temp.size()-1 ; i++) {
                    if(temp[i] <= temp[i+1]) return false ;
                }
            }
            level++ ;           
        }
        return true ;
    }
};
