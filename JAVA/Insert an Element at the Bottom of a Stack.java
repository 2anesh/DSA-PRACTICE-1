class Solution {
    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        String ns="";
        while(!st.empty())
        ns=st.pop()+" "+ns;
        System.out.println(x+" "+ns);
        return st;
    }
}
