class Solution {
    static List<Long> jugglerSequence(Long n) {
        List<Long> arr= new ArrayList<Long>();
        arr.add(n);
        while(n>1){
            if(n%2==0){
                n =(long) Math.pow(n,(float)1/2);
                arr.add(n);
            }
            else{
                n= (long)Math.pow(n,(float)3/2);
                arr.add(n);
            }
        }
        return arr;
        
    }
}
