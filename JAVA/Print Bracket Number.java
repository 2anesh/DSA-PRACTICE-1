class Solution {
    ArrayList<Integer> bracketNumbers(String str) {
    Stack<Integer> stack = new Stack<>();
    ArrayList<Integer> list= new ArrayList();
    int count=0;
    for(int i=0;i<str.length();i++){
       if(str.charAt(i)=='('){
           count++;
           stack.push(count);
           list.add(count);
       } 
        if(str.charAt(i)==')'){
            list.add(stack.pop());
        }
    }
     return list;
    }
}
