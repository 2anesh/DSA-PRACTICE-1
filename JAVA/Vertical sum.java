class Pair {
    Node n;
    int vl;
    
    Pair(Node node, int vlevel) {
        n = node;
        vl = vlevel;
    }
}
class Solution {
    public ArrayList<Integer> verticalSum(Node root) {
        Queue<Pair> q = new LinkedList<>();
        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()) {
            int n = q.size();
            while(n-- > 0) {
                Pair p = q.remove();
                Node node = p.n;
                int vlevel = p.vl;
                if(mp.get(vlevel) == null)
                    mp.put(vlevel, new ArrayList<>());
                mp.get(vlevel).add(node.data);
                if(node.left != null)
                    q.add(new Pair(node.left, vlevel - 1));
                if(node.right != null)
                    q.add(new Pair(node.right, vlevel + 1));
            }
        }
        ArrayList<Integer> res = new ArrayList<>(), vlevels = new ArrayList<>();
        for(HashMap.Entry<Integer, ArrayList<Integer>> m: mp.entrySet()) 
            vlevels.add(m.getKey());
        Collections.sort(vlevels);
        for(int vl: vlevels) {
            ArrayList<Integer> arr = mp.get(vl);
            int sum = 0;
            for(int num: arr)
                sum += num;
            res.add(sum);
        }
                    return res;
    }
}
