class Solution
{
    public:
    void sort(Node **head)
    {
        for(Node* p=*head; p!= NULL ; p=p->next){
            for(Node* q =p->next; q != NULL; q =q->next){
                if(p->data > q->data){
                    swap(p->data, q->data);
                }
            }
        }
    }
};
