class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast){
            if(fast -> next != NULL){
                fast = fast -> next;
                fast = fast -> next;
            }
            else break;
            slow = slow -> next;
            
            if(fast == slow) return true;
        }
        
        return false;
    }
};
