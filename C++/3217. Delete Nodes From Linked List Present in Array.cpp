class Solution {
    bool binarySearch(vector<int>&nums,int ele){
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == ele) return true;
            else if(nums[mid] > ele)e=mid-1;
            else s=mid+1;
        }
        return false;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
if(!head ) return NULL;
         const int siz = 1e5 + 1;
vector<int> visited(siz, -1);
        sort(nums.begin(),nums.end());
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prev = dummyNode,*curr=head;
        prev->next =curr;
        while(curr){
if( visited[curr->val] == 1 ||  visited[curr->val] == -1 && binarySearch(nums,curr->val)){
                visited[curr->val] == 1;
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
            }
            else {
                visited[curr->val] = 0;
                prev = curr;
                curr = curr->next;
            }
        }
        return dummyNode->next;
    }
};
