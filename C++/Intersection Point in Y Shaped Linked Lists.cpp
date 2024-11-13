class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
        int len1=0;
        int len2=0;
        Node* root1=head1;
        Node* root2=head2;
        while(root1)
        len1++,root1=root1->next;
        while(root2)
        len2++,root2=root2->next;
            root1=head1;
            root2=head2;
            int len_diff=abs(len1-len2);
        
        if(len1>len2){
            while(len_diff){
                root1=root1->next;
                len_diff--;
            }
            
        }
        else if(len2>len1){
            while(len_diff)
            len_diff--,root2=root2->next;
        }
        while(root1 && root2){
            if(root1==root2)
            return root1->data;
            root1=root1->next;
            root2=root2->next;
        }
        return -1;
    }
};
