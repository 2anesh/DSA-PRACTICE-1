class Solution {
    public Node flattenBST(Node root) {
        Node dummy = new Node(-1);
        Node current = dummy;
        Stack<Node> stack = new Stack<>();
        Node node = root;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            current.right = node;
            current = current.right;
            node.left = null; // Set left child to null
            node = node.right;
        }
        return dummy.right;
    }
}
