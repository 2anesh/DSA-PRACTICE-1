class Solution {
    static Long reversedBits(Long x) {
      String s=Long.toBinaryString(x);
      StringBuffer sb=new StringBuffer(s);
      sb.reverse();
      for(int i=sb.length();i<32;i++){
          sb.append("0");
      }
      long number = Long.parseLong(sb.toString(), 2);
      return number;
    }
};
