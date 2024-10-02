class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] sort = new int[arr.length];
        for(int i=0;i<arr.length;++i)
            sort[i] = arr[i];
        Arrays.sort(sort);
        HashMap<Integer,Integer> map = new HashMap<>();
        int ptx = 0, pre = -1;
        for(int i:sort)
        {
            if(i!=pre)
                ptx++;
            map.put(i,ptx);
            pre = i;
        }
        int[] res = new int[arr.length];
        ptx = 0;
        for(int i:arr)
        {
            if(map.containsKey(i))
                res[ptx++] = map.get(i);
        }
        return res;
    }
}
