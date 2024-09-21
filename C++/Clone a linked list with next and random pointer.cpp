class Solution {
  public:
    Node *copyList(Node *head) {
      if(head==NULL) return NULL;  
       Node* cur=head;
       while(cur!=NULL){
           Node* temp=cur->next;
           cur->next=new Node(cur->data);
           cur->next->next=temp;
           cur=temp;
       }
        cur=head;
      while(cur!=NULL){
      if(cur->next!=NULL){
      cur->next->random=(cur->random!=NULL)?cur->random->next:NULL;
     }
       cur=cur->next->next;
    }
      Node* orig=head; Node*copy=head->next;
       Node*temp=copy;
       while(orig!=NULL){
      orig->next=orig->next->next;
     copy->next=(copy->next!=NULL)?copy->next->next:copy->next;
        orig=orig->next;
        copy=copy->next;
      }
      return temp;
    }
};
