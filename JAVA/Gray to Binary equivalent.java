class Solution{
    public static int grayToBinary(int n) {
        int binary =0;
        for(; n!=0; n>>=1){
            binary ^=n;
        }
        return binary;
    }
       
}
