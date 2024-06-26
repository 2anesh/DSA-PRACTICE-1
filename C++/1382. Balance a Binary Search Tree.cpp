class Solution {
    void inOrder(TreeNode* root,vector<int>& arr)
    {   
        if(!root)
            return;
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }
    TreeNode* buildtree(vector<int>& sortedArr,int s,int e)
    {
        if(s>e)
            return NULL;
        int mid=s+(e-s)/2;
        int ele=sortedArr[mid];
        TreeNode* root=new TreeNode(ele);
        root->left=buildtree(sortedArr,s,mid-1);
        root->right=buildtree(sortedArr,mid+1,e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedArr;
        inOrder(root,sortedArr);
        return buildtree(sortedArr,0,sortedArr.size()-1);
    }
};
