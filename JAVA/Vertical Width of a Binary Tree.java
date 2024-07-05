class Solution {
    public int verticalWidth(Node root) {
        if (root == null) return 0;
        Set<Integer> set = new HashSet<>();
        Queue<Node> nodes = new LinkedList<>();
        Queue<Integer> distances = new LinkedList<>();
        nodes.add(root);
        distances.add(0);
        while (!nodes.isEmpty()) {
            Node current = nodes.poll();
            int hd = distances.poll();
            set.add(hd);
            if (current.left != null) {
                nodes.add(current.left);
                distances.add(hd - 1);
            }
            if (current.right != null) {
                nodes.add(current.right);
                distances.add(hd + 1);
            }
        }
        return set.size();
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        root1.left.left = new Node(4);
        root1.left.right = new Node(5);
        root1.right.left = new Node(6);
        root1.right.right = new Node(7);
        root1.right.left.right = new Node(8);
        root1.right.right.right = new Node(9);
        System.out.println(solution.verticalWidth(root1));
        Node root2 = new Node(1);
        root2.left = new Node(2);
        root2.right = new Node(3);
        System.out.println(solution.verticalWidth(root2)); 
    }
}
