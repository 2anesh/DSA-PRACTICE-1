class Solution {
    public static ArrayList<Integer> getPrimes(int n) {
        boolean[]Nprime=new boolean[n+1];
        seive(Nprime);
        ArrayList<Integer>ans = new ArrayList<>();
        if(n<4){
            ans.add(-1);
            ans.add(-1);
            return ans;
        }
        int start=2;
        int end =n-1;
        while(start<=end){
            if(Nprime[start]==false && Nprime[end]==false && start+end==n){
                ans.add(start);
                ans.add(end);
                return ans;
            }
            else if(Nprime[start]==false && Nprime[end]==false && start+end>n){
                end--;
            }
             else if(Nprime[start]==false && Nprime[end]==false && start+end<n){
                start++;
            }
            else if(Nprime[start]==false && Nprime[end]==true){
                end--;
            }
            else if(Nprime[start]==true && Nprime[end]==false){
                start++;
            }
            else {
                start++;
                end--;
            }
        }
        ans.add(-1);
        ans.add(-1);
        return ans;
    }
    public static void seive(boolean[] Nprime){
        int n = Nprime.length;
        for(int i=2;i<Math.sqrt(n);i++){
            for(int j=2*i;j<n;j=j+i){
                Nprime[j]=true;
            }
        }
    }
}
