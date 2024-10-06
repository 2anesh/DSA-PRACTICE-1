class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] arr1 = sentence1.split(" "); 
        String[] arr2 = sentence2.split(" "); 
        int start = 0,
        end1 = arr1.length - 1,
        end2 = arr2.length - 1;
        if (arr1.length > arr2.length){
            return areSentencesSimilar(sentence2, sentence1);
        }
        while (start < arr1.length && arr1[start].equals(arr2[start])) {
            start = start + 1;
        }
        while (end1 >= 0 && arr1[end1].equals(arr2[end2])) {
            end1 = end1 - 1;
            end2 = end2 - 1;
        }
        return start > end1;
    }
}
