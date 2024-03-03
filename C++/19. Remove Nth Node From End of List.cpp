class Solution {
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode*& head, int n) {
        int len = getLength(head);
        if (n == len)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        ListNode *prev = head;
        for (int i = 1; i < len - n; i++)
        {
            prev = prev->next;
        }
        ListNode *temp = prev->next;
        prev->next = prev->next->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};
