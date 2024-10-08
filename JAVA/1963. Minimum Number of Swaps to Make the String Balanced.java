class Solution {
    public int minSwaps(String s) {
        int c = 0;
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '['){
                st.push(']');
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    c++;
                }
            } 
        }
        return ((c+1)/2);
    }
}
