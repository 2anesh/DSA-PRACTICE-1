class Solution {
  public:
    Node* rotate(Node* head, int k) {
        vector<int>v;
        while(head){v.push_back(head->data); head=head->next;}
        k%=v.size();
        Node *aa=NULL, *bb=NULL;
        int p=k;
        while(p<v.size()){
            Node *a=new Node(v[p++]);
            if(!aa){aa=a; bb=a;}
            else{bb->next=a; bb=a;}
        }
        for(int i=0; i<k; i++){
            Node *a=new Node(v[i]);
            if(!aa){aa=a; bb=a;}
            else{bb->next=a; bb=a;}
        }
        return aa;
    }
};
