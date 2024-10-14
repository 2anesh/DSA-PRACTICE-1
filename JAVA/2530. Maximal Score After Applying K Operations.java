class Solution {
    public long maxKelements(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int it : arr) {
            pq.add(it);
        }
        long score = 0;
        for (int i = 0; i < k; i++) {
            if (!pq.isEmpty()) {
                int top = pq.poll();
                score += top;
                int newval = (int) Math.ceil(top / 3.0);
                pq.add(newval);
            }
        }
        return score;
    }
}
