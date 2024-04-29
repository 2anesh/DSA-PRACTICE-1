class Solution {
    public:
    Node* deleteK(Node *head,int K){
      if(K==1){
          return NULL;
      }
      Node* temp=head;
      Node* pre=NULL;
      long long count=1;
      while(temp!=NULL){
          if(count==K){
              pre->next=temp->next;
              count=0;
          }
          else{
              pre=temp;
          }
          temp=temp->next;
          count++;
      }
      return head;
    }
};
