class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> st=new HashSet<>();
        for(int i:nums){
            st.add(i);
        }
        ListNode result=new ListNode(0);
        ListNode curr=result;
        while(head!=null){
            if(!st.contains(head.val)){
                curr.next=head;
                curr=curr.next;
            }
            head=head.next;
        }
        curr.next=null;
        return result.next;
    }
}
