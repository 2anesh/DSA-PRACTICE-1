class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head)
        return {};
      stack<ListNode*> stack;
      while (head) {
        stack.push(head);
        head = head->next;  
      }
      ListNode* newHead{};
      while (!stack.empty()) {
        head = stack.top();
        if (!head->next)
          newHead = head;
        stack.pop();
        if (!stack.empty())
          head->next = stack.top();
      }
      head->next = {}; // To prevent cycle in linked list
      return newHead;
    }
};
