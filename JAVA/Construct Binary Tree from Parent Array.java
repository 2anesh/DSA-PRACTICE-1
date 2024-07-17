class Solution {
    public Node createTree(int parent[]) {
       HashMap<Integer,Node> hash=new HashMap<>();
       for(int i=0; i<parent.length; i++){
           hash.put(i,new Node(i));
       }
       int[] index=new int[parent.length];
       for(int i=0; i<parent.length; i++){
           if(parent[i]==-1) continue;
           Node node=hash.get(parent[i]);
           if(index[parent[i]]==0){
               node.left=hash.get(i);
               index[parent[i]]=-1;
           }
           else{
               node.right=hash.get(i);
           }
       }
       for(int i=0; i<parent.length; i++){
           if(parent[i]==-1) return hash.get(i);
       }
       return hash.get(parent[0]);
    }
}
