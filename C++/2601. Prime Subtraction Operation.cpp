class Solution {
public:
    vector<int> prime;
    void sieve(int M){
        bitset<1001> isPrime=0;
        isPrime.set();
        isPrime[0]=isPrime[1]=0;
        prime.reserve(int(M/max(1.0, log(M))));// use prime Numbery theorem
        int sqrtM=sqrt(M);
        for(int p=2; p<=sqrtM; p++){
            if (isPrime[p]==0) continue;
            prime.push_back(p);
            for(int j=p*p; j<=M; j+=p){
                isPrime[j]=0;
            }
        }
        int q=(sqrtM&1)?sqrtM+2:sqrtM+1;
        for(int p=q; p<=M; p+=2){
            if (isPrime[p])
                prime.push_back(p);
        }
    }
    void print(){
        for (int x:prime) cout<<x<<", ";
        cout<<endl;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size(), M=*max_element(nums.begin(), nums.end());
        sieve(max(M, 4));
        for(int i=n-2; i>=0; i--){
            if (nums[i+1]>nums[i]) continue;
            auto it=upper_bound(prime.begin(), prime.end(), nums[i]-nums[i+1]);
            if (it==prime.end()) return 0;
            int p=*it;
            nums[i]-=p;
            if (nums[i]<=0) return 0;
        }
        return 1;
    }
}; 
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
