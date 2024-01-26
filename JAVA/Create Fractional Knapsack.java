class Pair{
    double first;
    int second;
    public Pair(double f , int s){
        first = f;
        second = s;
    }
}
class Solution
{
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> Double.compare(b.first , a.first));
        for(int i = 0 ; i < n ; i++){
            pq.offer(new Pair( (double) arr[i].value/ arr[i].weight , arr[i].weight ) );
        }
        int curWt = 0 ;
        double profit = 0.0;
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            double val = p.first;
            int wt = p.second;
            if(curWt + wt <= W){
                curWt += wt;
                profit += (val * wt);
            }
            else {
                int rem = W - curWt;
                profit += (val * rem);
                break;
            }
        }
        return profit;
    }
}
