import java.util.TreeMap;
class Solution {
    public String[] findRelativeRanks(int[] score) {        
        int n = score.length;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < n; ++i){
            map.put(score[i], i);
        }
        String[] rank = new String[n];                
        int position = n;
        for (Map.Entry<Integer, Integer> entry: map.entrySet()){
            if (position == 3)
                rank[entry.getValue()] = "Bronze Medal";
            else if (position == 2)
                rank[entry.getValue()] = "Silver Medal";
            else if (position == 1)
                rank[entry.getValue()] = "Gold Medal";
            else 
                rank[entry.getValue()] = String.valueOf(position);
            --position;
        }        
        return rank;        
    }
}
