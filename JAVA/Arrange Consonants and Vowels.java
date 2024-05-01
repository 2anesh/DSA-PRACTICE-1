class Solution {
     public Node arrangeCV(Node head){
        if(head == null) return head;
        Node temp = head;
        Node vowels = new Node('a');
        Node vhead = vowels;
        while(temp.next != null){
            while(temp.next != null && temp.next.data != 'a' && temp.next.data != 'e' && temp.next.data != 'i' && temp.next.data != 'o' && temp.next.data != 'u' ){
                temp = temp.next;
            }
            if(temp.next != null){
                vowels.next = temp.next;
                vowels = vowels.next;
                if(temp.next.next == null) 
                    temp.next = null;
                else
                    temp.next = temp.next.next;
            }
        }
        vowels.next = head;
        if(head.data == 'a' || head.data == 'e' || head.data == 'i' || head.data == 'o' || head.data == 'u'){
            vowels.next = head.next;
            vhead = vhead.next;
            head.next = vhead;
            return head;
        }
        return vhead.next;
    }
}
