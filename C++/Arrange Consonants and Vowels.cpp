class Solution {
  public:
     struct Node* arrangeCV(Node* head) 
    {
        Node* consonantHead = nullptr;
        Node* consonantTail = nullptr;
        Node* vowelsHead = nullptr;
        Node* vowelsTail = nullptr;
        Node* temp = head;
        while(temp != nullptr)
        {
            char c = temp ->data;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                Node* newnode = new Node(c);
                if(vowelsHead == nullptr)
                {
                    vowelsHead = vowelsTail = newnode;
                }
                else
                {
                    vowelsTail ->next = newnode;
                    vowelsTail = vowelsTail ->next;
                }
            }
            else
            {
                Node* newnode = new Node(c);
                if(consonantHead == nullptr)
                {
                    consonantHead = consonantTail = newnode;
                }
                else
                {
                    consonantTail ->next = newnode;
                    consonantTail = consonantTail ->next;
                }
            }
            temp = temp->next;
        }
        if(vowelsHead == nullptr)
        {
            return consonantHead;
        }
        vowelsTail ->next = consonantHead;
        return vowelsHead;
    }
};
