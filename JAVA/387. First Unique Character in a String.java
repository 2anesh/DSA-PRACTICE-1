class Solution {
    public int firstUniqChar(String s) {
        for(char c:s.toCharArray()){
            int index=s.indexOf(c);
            int lastindex=s.lastIndexOf(c);
            if(index==lastindex){
                return index;
            }
        }
        return -1;
    }
}
