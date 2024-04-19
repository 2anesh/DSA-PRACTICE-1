class Solution
{
    ArrayList<Integer> findMissing(int a[], int b[], int n, int m)
    {
        ArrayList<Integer> res = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < m; i++){
            map.put(b[i], 1);
        }

        for(int j = 0; j < n; j++){
            if(map.get(a[j]) == null){
                res.add(a[j]);
            }
        }

        return res;
    }
}
