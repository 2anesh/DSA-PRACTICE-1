class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        for (int i = 0; i < arr.length; i++) {
            pq.offer(new double[] {
                -1.0 * arr[i] / arr[arr.length - 1],  
                i,  
                arr.length - 1 
            });
        }
        while (--k > 0) {
            double[] cur = pq.poll();
            int numeratorIndex = (int) cur[1];
            int denominatorIndex = (int) cur[2] - 1;
            if (denominatorIndex > numeratorIndex) {
                pq.offer(new double[] {
                    -1.0 * arr[numeratorIndex] / arr[denominatorIndex],  
                    numeratorIndex,  
                    denominatorIndex  
                });
            }
        }
        double[] result = pq.poll();
        return new int[]{arr[(int) result[1]], arr[(int) result[2]]};
    }
}
