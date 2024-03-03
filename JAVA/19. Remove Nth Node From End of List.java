class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode sentinel = new ListNode(-1, head);
        ListNode fastPointer = sentinel;
        ListNode slowPointer = null;
        while(n > 0){
            fastPointer = fastPointer.next;
            n--;
        }
        slowPointer = sentinel;
        while(fastPointer.next != null){
            fastPointer = fastPointer.next;
            slowPointer = slowPointer.next;
        }
        slowPointer.next = slowPointer.next.next;
        return sentinel.next;

    }
}
