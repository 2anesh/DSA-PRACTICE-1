class MyQueue {
private Stack<Integer> stack1 = new Stack<Integer>();
private Stack<Integer> stack2 = new Stack<Integer>();
public void push(int x) {
   stack1.push(x);
}
public int pop() {
    while(!stack1.isEmpty()){ 
        stack2.push(stack1.pop());
    }
    int res = stack2.pop();
    while(!stack2.isEmpty()){
        stack1.push(stack2.pop());
    }
    return res;
}
public int peek() {
    while(!stack1.isEmpty()){ 
        stack2.push(stack1.pop());
    }
    int res = stack2.peek();
    while(!stack2.isEmpty()){
        stack1.push(stack2.pop());
    }
    return res;
}
public boolean empty() {
    return stack1.isEmpty();
}    
}
