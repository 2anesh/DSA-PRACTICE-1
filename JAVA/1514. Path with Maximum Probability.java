class Solution {    
    class Node{
        int i;double w;
        Node(int i,double w){
            this.i=i;
            this.w=w;
        } 
    }    
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<List<Node>> adj = new ArrayList<>();        
        for(int i=0 ; i<n ; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i=0 ; i<edges.length ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj.get(u).add(new Node(v, wt));
            adj.get(v).add(new Node(u, wt));
        }
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> 
                    {if(a.w==b.w) return a.i-b.i; return Double.compare(b.w,a.w);});
        pq.add(new Node(start, 1));        
        HashSet<Integer> pst = new HashSet<>();
                while(!pq.isEmpty()) {
            Node node = pq.poll();
            int num = node.i;
            double prob = node.w;            
            pst.add(num);           
            if(num == end) {
                return prob;
            }           
            if(adj.get(num) != null) {
                for(Node it : adj.get(num)) {
                    if(!pst.contains(it.i)) {
                        pq.add(new Node(it.i, prob * it.w));
                    }
                }
            }
        }      
        return 0;
    }
}
