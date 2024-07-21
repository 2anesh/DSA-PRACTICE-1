class Solution {
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> rowOrder = topologicalSort(k, rowConditions);
        List<Integer> colOrder = topologicalSort(k, colConditions);        
        if (rowOrder == null || colOrder == null) {
            return new int[0][0];
        }        
        int[][] result = new int[k][k];
        Map<Integer, Integer> colPosition = new HashMap<>();       
        for (int i = 0; i < k; i++) {
            colPosition.put(colOrder.get(i), i);
        }        
        for (int i = 0; i < k; i++) {
            int num = rowOrder.get(i);
            result[i][colPosition.get(num)] = num;
        }       
        return result;
    }    
    private List<Integer> topologicalSort(int k, int[][] conditions) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= k; i++) {
            graph.add(new ArrayList<>());
        }
        int[] inDegree = new int[k + 1];        
        for (int[] condition : conditions) {
            int from = condition[0], to = condition[1];
            graph.get(from).add(to);
            inDegree[to]++;
        }        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }        
        List<Integer> order = new ArrayList<>();
        while (!queue.isEmpty()) {
            int node = queue.poll();
            order.add(node);
            for (int neighbor : graph.get(node)) {
                if (--inDegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }        
        return order.size() == k ? order : null;
    }
}
