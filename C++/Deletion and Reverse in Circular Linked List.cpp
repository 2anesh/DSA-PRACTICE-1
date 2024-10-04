class Solution {
  public:
    Node* reverse(Node* head) {
        vector<int> l;
        Node* temp = head;
        while ( temp ){
            l.push_back(temp->data);
            temp = temp->next;
            if ( temp == head ) break;
        }
        for ( int i = l.size()-1; i>=0; i-- ){
            temp->data = l[i];
            temp = temp->next;
        } return head;
    }
    Node* deleteNode(Node* head, int key) {
        vector<Node*> l; Node* temp = head;
        while ( temp ){
            l.push_back(temp);
            temp = temp->next;
            if ( temp == head ) break;
        }
        int ind = -1, n = l.size();
        for ( int i = 0; i<n; i++ ){
            if ( l[i]->data == key ){
                ind = i;
                break;
            }
        }
        if ( ind == -1 ) return head;
        else if ( ind == 0 ){
            l[ind]->next = NULL;
            l[n-1]->next = l[1];
            return l[1];
        } else if ( ind == n-1 )  {
            l[n-1]->next = NULL;
            l[n-2]->next = l[0];
            return head;
        } else {
            l[ind]->next = NULL;
            l[ind-1]->next = l[ind+1];
            return head;
        }
    }
};
