class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*Head=new ListNode(0);
        Head->next=head;
        ListNode* cur=Head;
        while(cur!=NULL)
        {
            int sum=0;
            cout<<cur->val<<" ";
            while(head!=NULL)
            {
                sum+=head->val;
                if(sum==0)
                {
                   cur->next=head->next; 
                }
                head=head->next;
            }
            cur=cur->next;
            
            if(cur!=NULL){
                head=cur->next;
            }
        }
        return Head->next; 
    }
};
