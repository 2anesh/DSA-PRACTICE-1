class Solution {
    public long kthElement(int k, int arr1[], int arr2[]) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int num : arr1) {
            list.add(num);
        }
        for (int num : arr2) {
            list.add(num);
        }
        Collections.sort(list);
        return list.get(k - 1);
    }
}
