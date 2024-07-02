class Solution {
  public:
    bool compute(Node* head) {
        string name1;
        while(head!=NULL)
        {
            name1=name1+head->data;
            head=head->next;
        }
        int i=0;
        int size=name1.size()-1;
        while(i<name1.size()/2)
        {
          if(name1[i]!=name1[size-i])
          return false;
          i++;
        }
    return true;
    }
};
