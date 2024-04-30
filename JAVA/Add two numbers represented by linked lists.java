class Solution{
    static Node reverseList(Node head)
    {
        Node p = head, pre = null;
        while(p != null)
        {
            Node nxt = p.next;
            p.next = pre;
            pre = p;
            p = nxt;
        }
        return pre;
    }
    static Node addTwoLists(Node num1, Node num2)
    {
        if(num1 == null)
            return num2;
        if(num2 == null)
            return num1;
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        Node dummy = new Node(-1);
        Node p = dummy;
        int carry = 0;
        while(num1 != null || num2 != null || carry == 1) 
        {
            int sum = 0;
            if(num1 != null) 
            {
                sum += num1.data;
                num1 = num1.next;
            }
            if(num2 != null) 
            {
                sum += num2.data;
                num2 = num2.next;
            }
            if(carry == 1)
                sum += carry;
            int val = sum % 10;
            carry = sum / 10;
            p.next = new Node(val);
            p = p.next;
        }
        dummy.next = reverseList(dummy.next);
        p = dummy.next;
        while(p != null && p.data == 0)
            p = p.next;
        return p == null ? new Node(0) : p;
    }
}
