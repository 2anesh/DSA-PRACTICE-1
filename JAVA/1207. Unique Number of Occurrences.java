class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for(int cnt : arr){
            if(freq.containsKey(cnt)) freq.put(cnt, freq.get(cnt) + 1); else freq.put(cnt, 1);
        }
        HashSet<Integer> freqSet = new HashSet<>(freq.values());
        return freq.size() == freqSet.size();
    }
}
