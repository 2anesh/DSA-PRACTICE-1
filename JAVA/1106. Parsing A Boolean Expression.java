class Solution {
    private static boolean isOperator(char ch){
        return ch == '!' || ch == '&' || ch == '|';
    }
    private static boolean isTrueOrFalse2(char op, Boolean f, Boolean t){
        if(op == '!'){
            return (f != null)? true : false;
        }
        if(f != null && t != null){
            return (op == '|')? true : false;
        }
        return (f != null)? false : true;        
    }
    private static char isTrueOrFalse(char op, Boolean f, Boolean t){
        boolean result = isTrueOrFalse2(op, f, t);
        if(result)
        return 't';
        return 'f';
    }
    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0; i < expression.length(); i++){
            char ch = expression.charAt(i);
            if(ch == ',')   continue;
            if(ch != ')'){
                stack.push(ch);
                continue;
            }
            Boolean f = null;
            Boolean t = null;
            while(stack.peek() != '('){
                if('f' == stack.peek())
                        f = false;
                else     
                        t = true;
                        stack.pop();
            }
            stack.pop();
            char op = stack.pop();
            char result = isTrueOrFalse(op, f, t);
            stack.push(result);
        }
        char ch = stack.pop();
        if(ch == 'f')
            return false;
        return true;
    }
}
