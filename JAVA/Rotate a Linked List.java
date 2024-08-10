class Solution {
    public Node rotate(Node head, int k) {
        Node temp = head;
        int i = 1;
        while(i++ < k) {
            temp = temp.next;
        }
        if(temp.next == null) return head;
        Node nextHead = temp.next;
        temp.next = null;
        temp = nextHead;
        while(temp.next != null) {
            temp = temp.next;
        }
        temp.next = head;
        return nextHead;
    }
}
