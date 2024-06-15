class Solution {
    public:
    long long getCount(int n) {
        vector<int> adj[10];
        adj[0] = {0, 8};
        adj[1] = {1, 2, 4};
        adj[2] = {1, 2, 3, 5};
        adj[3] = {2, 3, 6};
        adj[4] = {1, 4, 5, 7};
        adj[5] = {2, 4, 5, 6, 8};
        adj[6] = {3, 5, 6, 9};
        adj[7] = {4, 7, 8};
        adj[8] = {5, 7, 8, 9, 0};
        adj[9] = {6, 8, 9};
        vector<long long> prev(10, 1);
        for(int length=2; length<=n; length++){
            vector<long long> curr(10, 0);
            for(int digit=0; digit<=9; digit++){
                long long total = 0;
                for(auto &adjn : adj[digit]){
                    total += prev[adjn];
                }
                curr[digit] = total;
            }
            prev = curr;
        }
        long long ans=0;
        for(int i=0;i<=9;i++){
            ans += prev[i];
        }
        return ans;
    }
};
