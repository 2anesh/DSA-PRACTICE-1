class Solution{
    static ArrayList<Integer> recamanSequence(int n){
        ArrayList<Integer> al = new ArrayList<>();
        HashSet<Integer> h = new HashSet<>();
        al.add(0);
        h.add(0);
        for (int i=1;i<n;i++){
            if(al.get(i-1)-i>0 && h.contains(al.get(i-1)-i)==false){
                al.add(al.get(i-1)-i);
                h.add(al.get(i-1)-i);
            }else{
                al.add(al.get(i-1)+i);
                h.add(al.get(i-1)+i);
            }
        }
        return al;
    }
}
