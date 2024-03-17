class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        Code here
        unordered_map<int,int> m;
        int result=0;
        while(head1!=NULL){
            m[head1->data]++;
            head1=head1->next;
        }
        while(head2!=NULL){
            if(m.find(x-head2->data)!=m.end()){
                result++;
            }
            head2=head2->next;
        }
        return result;
    }
};
