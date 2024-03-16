class Solution
{
    public:
    void deleteNode(Node *del_node)
    {
       Node *p=del_node;
       Node *q=p->next;
       while(q->next!=NULL){
           swap(p->data,q->data);
           p=q;
           q=q->next;
       }
       swap(p->data,q->data);
       p->next=NULL;
       delete(q);
    }

};
