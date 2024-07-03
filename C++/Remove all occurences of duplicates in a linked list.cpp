class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        Node *prevnode = head;
        Node *currnode = head;
        while(currnode != NULL && currnode->next != NULL)
        {
            Node *nextnode = currnode->next;
            if(currnode->data != nextnode->data)
            {
                prevnode = currnode;
                currnode = nextnode;
            }
            else
            {   
                int val = currnode->data;
                if(currnode == head)
                {
                    while(head!=NULL && head->data == val)
                    {
                        head = head->next;
                    }
                    currnode = head;
                    prevnode = head;
                }
                else
                {
                    while(currnode != NULL && currnode->data == val)
                    {
                        currnode = currnode->next;
                    }
                    prevnode->next = currnode;
                }
            }
        }
        return head;
    }
};
