class Solution {
    public double averageWaitingTime(int[][] customers) {
        long time=customers[0][0];
        long w_time=0;
        for(int[] cus:customers){
            if(time<cus[0]){
                time=cus[0];
            }
            time+=cus[1];
            w_time+=time-cus[0];
        }
        return (double)w_time/customers.length;
    }
}
