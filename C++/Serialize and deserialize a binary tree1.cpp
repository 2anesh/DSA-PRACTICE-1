class Solution {
  public:
    void in(Node*root,vector<int>&arr)
    {
        if(root==NULL)
        {
            return;
        }
        
        in(root->left,arr);
        arr.push_back(root->data);
        in(root->right,arr);
    }
    Node* bsthelper(vector<int>&arr,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int mid=(start+end)/2;
        Node*root=new Node(arr[mid]);
        root->left=bsthelper(arr,start,mid-1);
        
        root->right=bsthelper(arr,mid+1,end);
        
        return root;
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>arr;
        in(root,arr);
        return arr;
    }
    Node *deSerialize(vector<int> &arr) {
        return bsthelper(arr,0,arr.size()-1);
        
    }
};
