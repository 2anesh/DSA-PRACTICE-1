class Solution {
    public int minAddToMakeValid(String s) {      
        Stack<Character> st = new Stack();         
        for(int i=0;i<s.length();i++)
        {
            boolean bol = true;
            if(s.charAt(i)=='(')
            {
                 st.push('(');
                 bol = false;
            }
            else if(!st.empty() && s.charAt(i)==')' && st.peek()=='(')
            {
                st.pop();
                bol = false;
            }
            if(bol)
            st.push(s.charAt(i));
        }
        return st.size();
    }
}
