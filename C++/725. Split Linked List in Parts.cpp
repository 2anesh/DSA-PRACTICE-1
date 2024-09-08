class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        vector<ListNode*>v(k,NULL);
        int p=len/k;
        int extra=len%k;
        temp=head;
        int j=0;
        while(temp!=NULL){
            ListNode*c=temp;
            ListNode* x=new ListNode(-1);
            ListNode*curr= x;
            for(int i=0;i<p;i++){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
            }
            if(extra>0){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
                extra--;
            }
            v[j]=x->next;
            j++;
        }
        return v;
    }
};
