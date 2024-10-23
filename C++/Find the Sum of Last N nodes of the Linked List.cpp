class Solution {
  public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        
        struct Node* temp=head;
        int cnt=0;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        if(n==cnt){
            int sum=0;
            struct Node* curr=head;
            
            while(curr!=NULL){
                sum=sum+curr->data;
                curr=curr->next;
            }
            
            return sum;
         }
        
         else if(n<cnt){
             
            struct Node* tp=head;
             int k=0;
             int sum=0;
             while(tp!=NULL&&k!=(cnt-n)){
                 tp=tp->next;
                 k++;
             }
             
             while(tp!=NULL && n>0){
                 sum=sum+tp->data;
                 tp=tp->next;
                 n--;
             }
             
             return sum;
         }
    }
};
