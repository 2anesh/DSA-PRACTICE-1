class Solution {
    public ListNode middleNode(ListNode head) {
        if(head.next==null)return head;
        int count=1;
        ListNode curr=head;
        ListNode c=head;
         ListNode ansList=new ListNode();
        while(curr.next!=null){
            count++;
            curr=curr.next;
        }
        int ans=0;
        if(count/2==0){
            ans=count/2+1;
        }
        else{
            ans=count/2;
        }
        
        while(ans!=0){
            
            c=c.next;
            ans--;

        }
        if(ans==0){
                return ansList=c;
            }
    return ansList;
    }
}
