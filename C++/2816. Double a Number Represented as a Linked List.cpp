class Solution {
public:
    ListNode* reverseList(ListNode* cur) {
        ListNode* prev=NULL;
        ListNode* fast = cur->next;
        while(cur) {
            cur->next = prev;
            prev = cur;
            cur = fast;
            if(fast) fast = fast->next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reverseList(head);
        head = temp;
        int rem=0;        
        ListNode* list = new ListNode;
        while(temp) {
            int ttal = temp->val*2+rem;
            ListNode* res = new ListNode(0);
            list->val = ttal%10;
            rem = ttal/10;
            res->val = rem;
            res->next = list;
            list = res;
            temp = temp->next;
        }
        return (rem>0)? list:list->next;
    }
};
