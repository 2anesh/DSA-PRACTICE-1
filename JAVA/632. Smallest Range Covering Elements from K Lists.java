class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]-b[0];
            }
        });
        int k = nums.size();
        int max = Integer.MIN_VALUE;
        for(int i=0;i<k;i++){
            int minVal = nums.get(i).get(0);
            pq.offer(new int[]{minVal, i, 0});  
            max = Math.max(max, minVal);
        }
        int ans[] = {0, Integer.MAX_VALUE};
        while(true){
            int curr[] = pq.poll();
            int minEl=curr[0], listIndex=curr[1], elementIndex=curr[2];
            if(max-minEl < ans[1]-ans[0]){
                ans[0] = minEl;
                ans[1] = max;
            }
            if(elementIndex == nums.get(listIndex).size()-1) break;
            int next = nums.get(listIndex).get(elementIndex+1);
            max = Math.max(max, next);
            pq.offer(new int[]{next, listIndex, elementIndex+1});
        }
        return ans;
    }
}
