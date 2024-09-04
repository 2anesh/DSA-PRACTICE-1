class Solution {
public:
    int getrightChildIndex(string traversal, int lo, int hi, int d_count)
    {
        int count = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (i > 0 && traversal[i - 1] != '-' && traversal[i] == '-')
            {
                int j = i;
                while (traversal[j] == '-' && j <= hi)
                    j++;
                if (j - i == d_count)
                {
                    count++;
                    if (count == 2)  //1st one is for same level left child
                        return j;                    
                    i = j;
                }
            }
        }
        return -1;
    }
    TreeNode* recoverFromPreorderUtil(string traversal, int lo, int hi, int d_count)
    {
        if (lo > hi)
            return NULL;
        int val = 0;
        while(isdigit(traversal[lo]) && lo <= hi) 
        {
            val = val * 10 + (traversal[lo] - '0');
            lo++;
        }
        TreeNode *root = new TreeNode(val);
        if (lo == hi + 1)
            return root;
        int rightChildIndex = getrightChildIndex(traversal, lo, hi, d_count);
root->left = recoverFromPreorderUtil(traversal, lo + d_count, rightChildIndex == -1 ? hi : rightChildIndex - d_count - 1, d_count + 1);
        if (rightChildIndex != -1)
        root->right = recoverFromPreorderUtil(traversal, rightChildIndex, hi, d_count + 1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        if (traversal.empty())
            return NULL;        
        int d_count = 1;
        return recoverFromPreorderUtil(traversal, 0, traversal.length() - 1, d_count);
    }
};
