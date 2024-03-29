class Solution {
    public boolean isEularCircuitExist(int v, ArrayList<ArrayList<Integer>> adj) {
       for(int i=0;i<v;i++) 
           if(((adj.get(i).size())&1)!=0) return false;
       
       return true;
    }
}
