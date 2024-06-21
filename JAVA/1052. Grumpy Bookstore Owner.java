class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n=customers.length;
        int cur=0,max=0;
        for(int i=0;i<minutes;i++){
            cur+=customers[i]*grumpy[i];
        }
        max=cur;
        int i=0,j=minutes;
        while(j<n){
            cur+=customers[j]*grumpy[j];
            cur-=customers[i]*grumpy[i];
            max=Math.max(cur,max);
            i++;
            j++;
        }
        int totalSatisfied=max;
        for(int z=0;z<n;z++){
            
           totalSatisfied+=customers[z]*(1-grumpy[z]); 
        }
        return totalSatisfied;
    }
}
