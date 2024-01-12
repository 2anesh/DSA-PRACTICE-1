class GfG {
    // Function to reverse first k elements of a queue.
    public Queue<Integer> modifyQueue(Queue<Integer> q, int k) {
        // add code here.
        Stack<Integer> s=new Stack<Integer>();
        Queue<Integer> a=new LinkedList<Integer>();
        while(k>0)
        {
            s.add(q.peek());
            q.remove();
            k--;
        }
        while(!s.empty())
        {
            a.add(s.pop());
        }
        while(!q.isEmpty())
        {
            a.add(q.remove());
        }
        return a;
    }
}
