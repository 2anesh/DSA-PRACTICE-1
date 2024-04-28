class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if(head->next == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL && fast->next != NULL && fast->next ->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};
