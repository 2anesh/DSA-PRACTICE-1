class Solution{
	public:
		int nthStair(int n){
		    int ans = 0;
		    int one = n;
		    int two = 0;
		    int su = n;
		    while(su == n && one>=0 && two<=n/2){
		        su = one*1 + two*2;
		        one-=2;
		        two++;
		        ans++;
		    }
		    return ans;
		}
};
