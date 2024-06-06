class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {        
        if (hand.length % groupSize != 0) return false;
        if (groupSize == 1) return true;
        Map<Integer, Integer> m = new HashMap<>();
        for (int i=0; i<hand.length; i++) {
            if (m.containsKey(hand[i])) m.put(hand[i], m.get(hand[i]) + 1);
            else m.put(hand[i], 1);
        }
        int[] arr = new int[m.size()];
        int idx = 0;
        for (int val : m.keySet()) arr[idx++] = val;
        Arrays.sort(arr);        
        for(idx = 0; idx<arr.length; idx++) {
            while (m.get(arr[idx]) != 0) {
                int val = arr[idx];
                m.put(val, m.get(val) - 1);
                for (int i=val + 1; i< (val + groupSize); i++) {
                    if (m.containsKey(i) && m.get(i) > 0) {
                        m.put(i, m.get(i) - 1);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
