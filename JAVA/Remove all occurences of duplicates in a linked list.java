class Solution {
    public Node removeAllDuplicates(Node head) {
        Node dummy = new Node(0);
        dummy.next = head;
        Node prev2 = dummy;
        Node curr = dummy;
        curr = curr.next;
        while(curr != null && curr.next != null) {
            boolean d = false;
            while(curr != null && curr.next != null && 
                    curr.data == curr.next.data) {
                curr = curr.next;
                d = true;
            }
            if(d) {
                prev2.next = curr.next;
                curr = curr.next;
            }
            else {
                prev2 = curr;
                curr = curr.next;
            }
        }        
        return dummy.next;
    }
}
