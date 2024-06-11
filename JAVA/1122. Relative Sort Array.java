class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {        
         Map<Integer, Integer> countMap = new TreeMap<>();
        for (int num : arr1) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        List<Integer> output = new ArrayList<>();
        for (int num : arr2) {
            if (countMap.containsKey(num)) {
                int count = countMap.get(num);
                while (count > 0) {
                    output.add(num);
                    count--;
                }
                countMap.remove(num);
            }
        }
        List<Integer> remaining = new ArrayList<>();
        for (int key : countMap.keySet()) {
            int count = countMap.get(key);
            while (count > 0) {
                remaining.add(key);
                count--;
            }
        }
        Collections.sort(remaining);
        output.addAll(remaining);
        int[] ans = new int[output.size()];
        for (int i = 0; i < output.size(); i++) {
           ans[i] = output.get(i);
        }
        return ans;
    }
}
