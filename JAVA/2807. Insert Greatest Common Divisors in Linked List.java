class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode current=head;
        while(current.next!=null)
        {
        ListNode temp=new ListNode();
        temp.next=current.next;
        temp.val=findMaxDiv(current.val,current.next.val);
        current.next=temp;
        current=temp.next;
        }
        return head;
    }
    public int findMaxDiv(int val1,int val2)
    {
        int div;
        if(val1<val2){div=val1;}else{div=val2;}
        while(!(val1%div==0&&val2%div==0))
        {div--;}
        return div;
    }
}
