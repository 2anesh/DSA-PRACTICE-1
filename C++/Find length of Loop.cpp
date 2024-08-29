class Solution {
  public:
    int countNodesinLoop(Node *head) {
        if(head==NULL || head->next==NULL)
        return 0;
        Node* curr=head;
        Node* forw=head->next->next;
        while(curr!=forw){
           curr=curr->next;
            forw=forw->next->next;
            if(forw==NULL || forw->next==NULL)
            return 0;
        }
        int count=1;
        curr=curr->next;
        while(curr!=forw){
            count++;
          curr=curr->next;
        }
        return count;
    }
};
