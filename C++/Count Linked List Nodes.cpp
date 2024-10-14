class Solution {
  public:
    int getCount(struct Node* head) {
        Node *slow=head;
        Node *fast=head;
        int count=0;
        while(fast && fast->next){
            count++;
            slow=slow->next;
            fast=fast->next->next;
        }
        int result;
        if(fast==NULL){
           result=2*count; 
        }
       else{ 
           result=2*count+1;
           
       }
        return result;
        
    }
};   
