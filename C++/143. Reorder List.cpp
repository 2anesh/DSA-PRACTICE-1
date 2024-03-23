class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(!head || !head->next){
            return;
        }
        fast = fast->next->next;
        slow = slow->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *headRightList = slow->next;
        ListNode *temp = NULL;
        slow->next = NULL;
        ListNode *headNewList = NULL;
        while(headRightList){
            temp = headRightList->next;
            headRightList->next = headNewList;
            headNewList = headRightList;
            headRightList = temp;

        }
        ListNode *headLeftList = head;
        headRightList = headNewList;
        while(headLeftList && headRightList){
            temp = headLeftList->next;
            headLeftList->next = headRightList;
            headLeftList = temp;
            temp = headRightList->next;
            headRightList->next = headLeftList;
            headRightList = temp;
        }

    }
};
