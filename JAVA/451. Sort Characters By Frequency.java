class Solution {
    public String frequencySort(String s) {
        char[] chars = s.toCharArray(); 
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : chars) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }
        List<Character> sortedChars = new ArrayList<>(frequencyMap.keySet());
        Collections.sort(sortedChars, (a, b) -> frequencyMap.get(b) - frequencyMap.get(a));
        StringBuilder result = new StringBuilder();
        for (char c : sortedChars) {
            int frequency = frequencyMap.get(c);
            for (int i = 0; i < frequency; i++) {
                result.append(c);
            }
        }
        return result.toString();
    }
}
