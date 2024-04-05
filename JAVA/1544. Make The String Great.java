class Solution {
    public String makeGood(String s) {
    if(s.length()==1) return s;
    StringBuilder sb = new StringBuilder();
    int i=0;
    for(char c: s.toCharArray()){
        if(i!=0 && Math.abs((sb.charAt(i-1))-c) == 32){
             sb.deleteCharAt(i-1);
             i--;
        }else{
            sb.append(c);
            i++;
        }
    }
    return sb.toString();
    }
}
