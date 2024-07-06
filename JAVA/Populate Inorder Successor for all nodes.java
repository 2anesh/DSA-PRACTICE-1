class Solution {
    private Node previous = null; 
    public void populateNext(Node root) {
        if (root == null) {
            return;
        }
        populateNext(root.left);
        if (previous != null) {
            previous.next = root;
        }
        previous = root;
        populateNext(root.right);
    }
}
