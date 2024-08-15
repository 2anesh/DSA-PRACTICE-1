class Solution {
    public Node addOne(Node head) {
        Node temp = reverse(head);
        Node ans = null; 
        Node node = null; 
        int carry = 1;
        while (temp != null) {
            int sum = temp.data + (carry ==1 ? 1 : 0); 
            carry = sum / 10; 
            sum = sum % 10; 
            Node newNode = new Node(sum);
            if (ans == null) {
                ans = newNode;
                node = newNode;
            } else {
                node.next = newNode;
                node = node.next;
            }
            temp = temp.next;
        }
        if (carry==1) {
            node.next = new Node(1);
        }
        Node fans = reverse(ans);
        return fans;
    }
    public Node reverse(Node head) {
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            Node sec = curr.next;
            curr.next = prev;
            prev = curr;
            curr = sec;
        }
        return prev;
    }
}
