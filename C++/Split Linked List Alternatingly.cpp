class Solution {
  public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        struct Node *s1h,*s2h,*s1,*s2,*t=head->next;
        s1=head;
        s2=head->next;
        s1h=s1;
        s2h=s2;
        if(t!=nullptr)t=t->next;
        int i=1;
        while(t!=nullptr){
            if(i){
                s1->next=t;
                s1=s1->next;
                i=0;
            }else{
                s2->next=t;
                s2=s2->next;
                i=1;
            }
            t=t->next;
        }
        s1->next=nullptr;
        s2->next=nullptr;
        return {s1h,s2h};
    }
};
