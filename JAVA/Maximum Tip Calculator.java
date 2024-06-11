class Solution {
    static class TipIndex{
        int diff;
        int index;
        TipIndex(int a, int b, int i){
            diff = a-b;
            index = i;
        }
    }
    public static long maxTip(int n, int x, int y, int[] arr, int[] brr) {
        ArrayList<TipIndex> al = new ArrayList<>();
        for(int i=0;i<n;i++){
            al.add(new TipIndex(arr[i], brr[i], i));
        }
        Collections.sort(al, new Comparator<TipIndex>() {
            @Override
            public int compare(TipIndex t1, TipIndex t2) {
                return Integer.compare(t2.diff, t1.diff);
            }
        });
        long tip1=0, tip2=0, tip3=0;
        for(int i=0;i<n-y;i++){
            tip1  =  tip1 + (long)(arr[al.get(i).index]);
        }
        for(int i=n-y;i<x;i++){
            if(al.get(i).diff>=0){
                tip2 = tip2 + (long)(arr[al.get(i).index]);
            }
            else{
                tip2= tip2+(long)(brr[al.get(i).index]);
            }
        }
        for(int i=x;i<n;i++){
            tip3  = tip3+ (long)(brr[al.get(i).index]);
        }
        return (long)(tip1+tip2+tip3);
    }
}
