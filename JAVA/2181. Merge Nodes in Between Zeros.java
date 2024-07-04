class Solution {
    public ListNode mergeNodes(ListNode head) {
     ListNode root=new ListNode();
     ListNode cur=root;
     ListNode temp=head;
     int sum=0;
     while(temp!=null){
       if(temp.val==0&&sum!=0){
         cur.next=new ListNode(sum);
         cur=cur.next;
         sum=0;
       }
       sum=sum+temp.val;
       temp=temp.next;
     }
     return root.next;
    }
}
