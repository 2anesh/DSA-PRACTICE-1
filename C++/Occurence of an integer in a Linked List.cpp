class Solution {
  public:
    int count(struct Node* head, int key) {
        int ans = 0;
        Node* curr = head;
        while(curr)
        {
            if(curr->data == key)
            {
                ans++;
            }
            curr = curr->next;
        }
        return ans;
    }
};
