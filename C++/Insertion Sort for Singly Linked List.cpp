class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        //code here
        if (!head || head->next == NULL)
            return head;
        Node* extra = new Node(-1);
        extra->next = head;
        
        Node * curr = head->next;
        Node * prev = head;
        while(curr != NULL){
            Node * temp = extra;
            if (prev->data < curr->data){
                curr = curr->next;
                prev = prev->next;
                continue;
            }
            while(temp->next->data < curr->data){
                temp = temp->next;
            }
            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = prev->next;

        }
        return extra->next;
    }
    
};

 
