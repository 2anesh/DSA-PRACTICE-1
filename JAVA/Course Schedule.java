class Solution {
    static int[] findOrder(int n, int m, ArrayList<ArrayList<Integer>> prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        int[] inDegree = new int[n];

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites.get(i).get(0);
            int prerequisiteForCourse = prerequisites.get(i).get(1);
            graph[prerequisiteForCourse].add(course);
            inDegree[course]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < inDegree.length; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }
        int[] answer = new int[n];
        int index = 0;
        while (!queue.isEmpty()) {
            int curr = queue.remove();
            answer[index++] = curr;
            for (int e : graph[curr]) {
                inDegree[e]--;

                if (inDegree[e] == 0) {
                    queue.add(e);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0) {
                return new int[0];
            }
        }
        return answer;
    }
}
