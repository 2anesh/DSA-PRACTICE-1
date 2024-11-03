class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        while(*head!=NULL && (*head)->next!=NULL) *head=(*head)->next->next;
        return *head==NULL;
    }
};
