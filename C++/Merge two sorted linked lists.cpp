class Solution {
  public:
    //Node* sortedMerge(Node* head1, Node* head2) {
        // code here
    //}
    
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* ans=new Node(-1);
        Node* temp=ans;
        Node* temp1=head1,*temp2=head2;
        
        while(temp1 && temp2){
            if(temp1->data<temp2->data){
                temp->next=temp1;
                temp1=temp1->next;
                temp=temp->next;
            } else{
                temp->next=temp2;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        
        while(temp1){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        
        while(temp2){
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
        
        return ans->next;
    }
};
