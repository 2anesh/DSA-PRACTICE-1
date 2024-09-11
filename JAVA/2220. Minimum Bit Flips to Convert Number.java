class Solution {
    public int minBitFlips(int start, int goal) {
        int count=0;
        int bit=(start^goal);
        while(bit>0){
            if((bit&1)==1)count++;
            bit=bit>>1;
        }
        return count;
    }
}
