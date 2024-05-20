class Solution {
public:
    #define lli long long int
    lli solve(lli x, lli n, lli M) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x % M;
        if(n % 2 == 0)
            return solve((x * x) % M, n / 2, M) % M;
        else
            return ((x % M) * solve((x * x) % M, n / 2, M)) % M;
    }
	lli PowMod(lli x, lli n, lli M) {
	    return solve(x, n, M);
	}
};
