class Solution {
public:
    int findComplement(int num) {
        if(num==1)
        return 0;
        long long int ans=0,rem,mul=1;
        while(num)
        {
            rem = num%2;
            rem = rem^1;
            num = num/2;
            ans = ans + rem * mul;
            mul = mul *2;
        }
        return ans;
    }
};
