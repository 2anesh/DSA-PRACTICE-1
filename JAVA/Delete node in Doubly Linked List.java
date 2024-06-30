class Solution {
    public Node deleteNode(Node head, int x) {
        if(x==1){
          return head.next;
        }
        Node temp = head;
        for(int i = 1;i<x-1;i++){
            temp = temp.next;
        }
         temp.next = temp.next.next;
         if(temp.next!=null){
             temp.next.prev = temp;
         }
        return head;
    }
}
