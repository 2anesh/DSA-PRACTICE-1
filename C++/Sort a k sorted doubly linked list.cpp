class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
{
        priority_queue < int, vector<int>, greater<int> > pq;
        DLLNode *temp=head;
        DLLNode *put =head;
        while(temp!=NULL)
        {
            pq.push(temp->data);
            if(pq.size()>k)
            {
                put->data=pq.top();
                pq.pop();
                put=put->next;
            }
            temp=temp->next;
        }
        while(!pq.empty())
        {
            put->data=pq.top();
            pq.pop();
            put=put->next;
        }
        return head;
    }
};
