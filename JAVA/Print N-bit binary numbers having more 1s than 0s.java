class Solution {
    
    void solve(int n, ArrayList<String> arr,String temp,int countZ,int countO,boolean f){
        if(n==0){
            if(f){
                arr.add(temp);
            }
            return;
        }
        if(countO>countZ)
        solve(n-1,arr,temp+"0",countZ+1,countO,true);
        if(countO>=countZ)
        solve(n-1,arr,temp+"1",countZ,countO+1,true);
    }
    ArrayList<String> NBitBinary(int N) {
        // code here
        ArrayList<String> ans=new ArrayList<>();
        solve(N,ans,"",0,0,true);
        Collections.sort(ans,Collections.reverseOrder());
        return ans;
    }
}
