class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck); 
        int n = deck.length;
        int[] result = new int[n];
        Queue<Integer> indexQueue = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            indexQueue.add(i);
        }
        for(int card : deck) {
            result[indexQueue.remove()] = card;
            if(!indexQueue.isEmpty()) {
                indexQueue.add(indexQueue.remove());
            }
        }
        return result;
    }
}
