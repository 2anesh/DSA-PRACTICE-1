class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        String str="123456789";
        List<Integer> res=new ArrayList<>();
        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<=str.length();j++){
                String substr=str.substring(i,j);
                int num=Integer.parseInt(substr);
                if(num>=low && num<=high){
                    res.add(num);
                }
            }
        }
        Collections.sort(res);
        return res;
    }
}
