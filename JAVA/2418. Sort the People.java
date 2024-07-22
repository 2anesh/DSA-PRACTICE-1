class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Map<Integer, String> mapping = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            mapping.put(heights[i], names[i]);
        }
        Integer[] heightsArray = Arrays.stream(heights).boxed().toArray(Integer[]::new);
        Arrays.sort(heightsArray, (a, b) -> b - a);
        for (int i = 0; i < n; ++i) {
            names[i] = mapping.get(heightsArray[i]);
        }
        return names;
    }
}
