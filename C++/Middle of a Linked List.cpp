class Solution {
  public:
    int getMiddle(Node* head) {
        int cnt = 0;
        Node* t = head;
        while(t)
        {
            t = t->next;
            cnt++;
        }
        int ind = cnt/2;
        int i = 1;
        Node* curr = head;
        while(i <= ind)
        {
            curr = curr->next;
            i++;
        }
        return curr->data;
    }
};
