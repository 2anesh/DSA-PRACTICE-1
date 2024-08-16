class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int result = 0;
        int minVal = arrays.get(0).get(0);
        int maxVal = arrays.get(0).get(arrays.get(0).size() - 1);        
        for (int i = 1; i < arrays.size(); i++) {
            int currentMin = arrays.get(i).get(0);
            int currentMax = arrays.get(i).get(arrays.get(i).size() - 1);
            result = Math.max(result, Math.abs(currentMax - minVal));
            result = Math.max(result, Math.abs(maxVal - currentMin));
            minVal = Math.min(minVal, currentMin);
            maxVal = Math.max(maxVal, currentMax);
        }        
        return result;
    }
}
