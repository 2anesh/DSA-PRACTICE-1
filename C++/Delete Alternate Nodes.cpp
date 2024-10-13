class Solution {
  public:
    void deleteAlt( Node *head) {
     if(head==nullptr || head->next==nullptr){
         return;
     }
     Node* curr=head;
      Node* prev=head;
      Node* nexty=nullptr;
     while(curr && curr->next){
      nexty=curr->next;
      curr=curr->next->next;
      prev->next=curr;
      prev=curr;
      delete nexty;
     }
     return;
    }
};
