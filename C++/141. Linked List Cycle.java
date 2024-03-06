class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast;
        ListNode *slow;
        fast = slow = head;
        if(!head){
            return false;
        }
        while(fast){
            if(!fast->next) {return false;}
            fast = fast->next;
            if(!fast->next) {return false;}
            fast = fast->next;
            if(slow == fast){return true;}
            slow = slow->next;
        }
        return false;
    }
};
