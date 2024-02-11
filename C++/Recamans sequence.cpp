class Solution{
public:
    vector<int> recamanSequence(int n){
        unordered_map<int,int> mp;
        vector<int> res(n);
        res[0] = 0;
        res[1] = 1;
        mp[0] = 0;
        mp[1] = 1;
        for(int i =2; i<n; i++)
        {
            int x = res[i-1] -i;
            if(x > 0 && mp[x] == 0)
            {
                res[i] = x;
                mp[x]++;
            }
            else
            {
                x = res[i-1] + i;
                res[i] = x;
                mp[x]++;
            }
        }
        return res;
    }
};
