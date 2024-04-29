class Solution
{
 Node delete(Node head, int k)
    {
    Node temp = head;
    int i=1;
    if(i == k) {
        return null;
    }
    while(temp != null && temp.next != null) {
        if(i+1 == k) {
            temp.next = temp.next.next;
            i = 0;
        }
        i++;
        temp = temp.next;
    }
    return head;
    
}
}
