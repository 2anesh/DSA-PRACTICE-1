class Solution {
public:
    Node *reverseList(Node *head){
        Node *prev = NULL, *curr = head;
        while(curr!=NULL){
            Node *frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }
    int getLength(Node *head){
        int len = 0;
        Node *curr = head;
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }
        return len;
    }
    Node *removeZeros(Node *head){
        while(head!=NULL && head->data==0){
            head = head->next;
        }
        return head;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = removeZeros(head1);
        head2 = removeZeros(head2);
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        if(len1<len2){
            swap(head1,head2);
        }else if(len1==len2){
            Node *curr1 = head1, *curr2 = head2;
            while(curr1!=NULL && curr2!=NULL && curr1->data == curr2->data){
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            if(curr1==NULL && curr2==NULL) return new Node(0);
            if(curr1->data < curr2->data)
                swap(head1,head2);
        }
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        int carry = 0;
        while(head1!=NULL && head2!=NULL){
            int n1 = head1->data - carry;
            int n2 = head2->data;
            int val;
            if(n1>=n2){
                val = n1-n2;
                carry = 0;
            }else{
                val = (n1 + 10) - n2;
                carry = 1;
            }
            curr->next = new Node(val);
            curr = curr->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1!=NULL){
            int n1 = head1->data - carry;
            int val;
            if(n1<0){
                val = n1 + 10;
                carry = 1;
            }else{
                val = n1;
                carry = 0;
            }
            curr->next = new Node(val);
            curr = curr->next;
            head1 = head1->next;
        }
        Node *result = dummy->next;
        result = reverseList(result);
        result = removeZeros(result);
        return result;
    }
};
