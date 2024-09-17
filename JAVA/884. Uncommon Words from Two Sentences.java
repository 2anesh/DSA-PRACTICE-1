class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String,Integer> mp=new HashMap<>();
        String[] words=s1.split(" ");
        for(String word:words)
        {
            mp.put(word,mp.getOrDefault(word,0)+1);
        }   
        String[] words1=s2.split(" ");
        for(String word:words1)
        {
            mp.put(word,mp.getOrDefault(word,0)+1);
        }
        List<String> res=new ArrayList<>();
        for(Map.Entry<String,Integer> entry:mp.entrySet())
        {
            if(entry.getValue()==1)
            {
                res.add(entry.getKey());
            }
        }
        return res.toArray(new String[0]);
    }
}
