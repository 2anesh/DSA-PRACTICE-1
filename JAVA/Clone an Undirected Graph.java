class Solution{ 
    Node cloneGraph(Node node){
       if(node == null){ 
           return null;
       }   
       Queue<Node> q = new LinkedList<>(); 
       q.add(node); 
       HashMap<Node,Node> map = new HashMap<>(); 
       map.put(node, new Node(node.val)); 
       while(!q.isEmpty()){ 
           Node fn = q.poll();
           Node cpn = map.get(fn); 
           if(fn.neighbors != null)
           { 
               ArrayList<Node> clist = fn.neighbors;
               for( int i=0; i<clist.size(); i++){ 
                   Node ln  = clist.get(i); 
                   Node cl = map.get(ln); 
                   if(cl == null){ 
                       q.add(ln); 
                       cl = new Node(ln.val); 
                       map.put(ln ,cl);
                   } 
                   cpn.neighbors.add(cl);
               }
           }
       } 
       return map.get(node);
    }
}
