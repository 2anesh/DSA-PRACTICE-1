class Solution {
  public:
     Node* convert(vector<int> &nums, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = start + (end - start)/2;
        Node* head = new Node(nums[mid]);
        head->left = convert(nums, start, mid - 1);
        head->right = convert(nums, mid + 1, end);
        return head;
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums, 0, n - 1);
    }
};
