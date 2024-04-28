class Solution {
    Node deleteMid(Node head) {
        if (head == null || head.next == null)
            return null;
        Node slowPtr = head;
        Node fastPtr = head;
        Node prev = null;
        while (fastPtr != null && fastPtr.next != null) {
            prev = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }
        prev.next = slowPtr.next;
        return head;
    }
}
