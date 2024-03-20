class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode list2_lastNode=list2;
        while(list2_lastNode.next!=null) list2_lastNode=list2_lastNode.next;

        ListNode criticalNode=list1;
        int temp_a=a;
        while(true){
            temp_a--;
            if(temp_a<=0) break;
            criticalNode=criticalNode.next;
        }
        b=b-a+1;
        ListNode tempcriticalNode=criticalNode;
        while(tempcriticalNode.next!=null){
            if(b==0) break;
            tempcriticalNode=tempcriticalNode.next;
            b--;
        }
        criticalNode.next=list2;
        list2_lastNode.next=tempcriticalNode.next;

        return list1;
    }
}
