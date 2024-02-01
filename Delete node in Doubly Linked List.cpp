class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      
      if(x==1)
      {
          head_ref=head_ref->next;
          return head_ref;
      }
      
      int count=0;
      
      Node*temp=head_ref;
      
      while(count<x && temp)
      {
          count++;
          if(count==x)
          {
              temp->prev->next=temp->next;
              return head_ref;
              
          }
              
          else
          temp=temp->next;
      }
    }
};
