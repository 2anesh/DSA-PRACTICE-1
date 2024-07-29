class Solution {
    public int numTeams(int[] rating) {
        int total=0;
        for(int i=1;i<rating.length-1;i++)
        {
            int temp1=0;
            int temp2=0;
            int temp3=0;
            int temp4=0;
           for(int j=0;j<i;j++)
           {
              if(rating[j]<rating[i])
              temp1++;
              else
              temp3++;
           }
           for(int j=i+1;j<rating.length;j++)
           {
              if(rating[j]>rating[i])
              temp2++;
              else
              temp4++;
           }
           total += temp1*temp2;
           total += temp3*temp4;
        }
        return total;
    }
}
