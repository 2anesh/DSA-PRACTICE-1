class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            Node* front = temp -> next;
             temp -> next = prev;
             prev = temp;
            temp = front;
        }
        return prev;
    }
};
