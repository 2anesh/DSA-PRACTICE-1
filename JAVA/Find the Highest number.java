class Solution {
    public int findPeakElement(List<Integer> a) {
        Collections.sort(a);
        Collections.reverse(a);
        return a.get(0);
    }
}
