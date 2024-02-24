class Solution{
    public:
        int maxSum(int n){
            return n==0 ? 0 : max(max(n/2,maxSum(n/2)) + max(n/3,maxSum(n/3)) + max(n/4,maxSum(n/4)),n);
        }
};
