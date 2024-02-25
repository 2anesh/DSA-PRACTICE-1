class Solution {
public:
    int dsu(vector<int>& parent,int x){
        if(parent[x] == -1){
            return x;
        }
        else{
            return parent[x] = dsu(parent,parent[x]);
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int n = nums.size(),mx = *max_element(nums.begin(),nums.end());
        if(n == 1 && nums[0] == 1){
            return true;
        }
        vector<bool>f(mx+1,false);
        vector<int>parent(mx+1,-1); set<int>primes;
        for(int i = 0; i < n; i++){
            f[nums[i]] = 1;
        }
        if(f[1]){
            return false;
        }
        else{
            for(int j = 2; j <= mx; j++){
                if(f[j]){
                    vector<int>c;
                    bool check = false;
                    int k = j;
                    while(k % 2 == 0){
                        check = true;
                        k /= 2;
                    }
                    if(check){
                        c.push_back(2);
                    }
                    for(int p = 3; p * p <= k; p++){
                        check = false;
                        while(k % p == 0){
                            check = true;
                            k /= p;
                        }
                        if(check){
                            c.push_back(p);
                        }
                    }
                    if(k > 1){
                        c.push_back(k);
                    }
                    int paru = dsu(parent,c[0]); primes.insert(c[0]);
                    for(int p = 1; p < c.size(); p++){
                        primes.insert(c[p]);
                        int parv = dsu(parent,c[p]);
                        if(parv != paru){
                            parent[parv] = paru;
                        }
                    }
                    
                }
            }
            for(int i = 1; i <= mx; i++){
                dsu(parent,i);
            }
            int ans = 0;
            for(auto it : primes){
                if(parent[it] == -1){
                    ans++;
                }
            }
            return ans == 1;
        }
    }
};
