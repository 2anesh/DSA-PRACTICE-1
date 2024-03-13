class Solution {
    public int pivotInteger(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i;
        }
        int p=0;
        for(int i=1;i<=n;i++){
p+=i;
if(p==sum){
    return i;
}
sum=sum-i;
        }
        return -1;
    }
}
