class Solution {
   public ListNode middleNode(ListNode head) {
        ListNode slow = head;  
        ListNode fast = head; 
        while(fast!=null && fast.next !=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
      public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode prev = null;
        ListNode present = head;
        ListNode next = present.next;

        while (present != null) {
            present.next = prev;
            prev = present;
            present = next;
            if (next != null) {
                next = next.next;
            }
        }
        return prev;
      }
        
    public void reorderList(ListNode head){ 
        if (head == null || head.next == null) {
            return;
        }
        ListNode mid = middleNode(head);
        ListNode hs = reverseList(mid);
        ListNode hf = head; 
        while(hf!=null && hs!=null){    
            ListNode temp = hf.next;    
            hf.next = hs;   
            hf = temp; 
            temp = hs.next; 
            hs.next = hf;   
            hs = temp;      
        }
        if(hf!=null ){
            hf.next = null;
        }
    }
}
