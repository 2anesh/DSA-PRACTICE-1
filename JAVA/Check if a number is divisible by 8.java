class Solution{
    int DivisibleByEight(String s){
        if(s.length() == 0) return -1;
        int num = 0;
        num = Integer.parseInt(s.substring(Math.max(0, s.length() - 3)));
        if(num % 8 == 0) return 1;
        return -1;
    }
}
