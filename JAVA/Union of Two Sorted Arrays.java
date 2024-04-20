class Solution
{
    public static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m)
    {
        ArrayList<Integer> list = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num : arr1){
            if(!map.containsKey(num)){
                map.put(num, 1);
                list.add(num);
            }
        }
        for(int num : arr2){
            if(!map.containsKey(num)){
                map.put(num, 1);
                list.add(num);
            }
        }
        Collections.sort(list);
        return list;
    }
}
