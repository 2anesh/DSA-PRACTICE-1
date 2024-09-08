class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        ListNode ptr = head;
        while (ptr != null) {
            n++;
            ptr = ptr.next;
        }
        int partSize = n / k;
        int extra = n % k;
        ListNode[] ans = new ListNode[k];        
        ptr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = ptr;
            int currentPartSize = partSize + (extra > 0 ? 1 : 0); 
            extra--;
            for (int j = 0; j < currentPartSize - 1 && ptr != null; j++) {
                ptr = ptr.next;
            }
            if (ptr != null) {
                ListNode nextPart = ptr.next;
                ptr.next = null;
                ptr = nextPart;
            }
        }
        return ans;
    }
}
