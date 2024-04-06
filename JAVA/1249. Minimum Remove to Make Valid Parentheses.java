class Solution {
    public String minRemoveToMakeValid(String s) {        
        char [] chars = new char[s.length()];
        for(int i = 0; i < s.length(); i++)chars[i] = s.charAt(i);
        
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(chars[i] == '(')st.push(i);
            else if(chars[i] == ')'){
                if(st.size() == 0)chars[i] = '.';
                else st.pop();
            }
        }
        while(st.size() != 0)chars[st.pop()] = '.';
        
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < chars.length; i++){
            if(chars[i] != '.')ans.append(chars[i]);
        }
        return ans.toString();
            
    }
}
