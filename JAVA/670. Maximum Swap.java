class Solution {
    public int maximumSwap(int num) {
       int[] a = new int[10];
       Arrays.fill(a,-1);
       String s = Integer.toString(num);
       for(int i=0;i<s.length();i++)
       {
          int idx = s.charAt(i)-'0';
          a[idx]=i;
       } 
       for(int i=0;i<s.length();i++)
       {
          char currChar = s.charAt(i);
          int currIdx = currChar-'0';
          for(int digit=9;digit>currIdx;digit--)
          {
             if(a[digit]>i)
             {
                char[] charArray = s.toCharArray();
                char temp = charArray[i];
                charArray[i] = charArray[a[digit]];
                charArray[a[digit]] = temp;
                return Integer.parseInt(new String(charArray));
             }
           }
       }
       return num;
    }
}
