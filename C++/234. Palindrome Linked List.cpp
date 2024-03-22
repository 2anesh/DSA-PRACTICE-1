class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr && fastptr->next){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* prev = nullptr, *cur = nullptr, *next = slowptr;
        while(next){
            cur = next;
            next = next -> next;
            cur->next = prev;
            prev = cur;
        } 
        while(head != slowptr){
            if(head->val != cur->val) return false;
            head = head->next;
            cur = cur->next;
        }

        return true;

    }
};
