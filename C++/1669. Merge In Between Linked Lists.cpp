class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *start,*last,*head=list1;
        int num=1;
        while(list1 != NULL){
            if(num==a){
                start=list1;
            }
            else if(num==b+2){
                last=list1;
            }
            list1=list1->next;
            num++;
        }
        start->next=list2;
        while(start->next!=NULL){
            start=start->next;
        }
        start->next=last;
        return head;
    }
};
