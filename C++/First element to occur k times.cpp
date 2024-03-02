class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        vector<int> f(201, 0);
        for(int i = 0; i < n; i++){
            f[a[i]]++;
            if(f[a[i]] == k) return a[i];
        }
        return -1;
    }
};
