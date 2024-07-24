class Solution {
public:
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) {
        vector<pair<int, int>> newi;
        for (auto i : nums) {
            long long n = 0;
            int t = i;
            long long place = 1;
            if(t==0)
                n = map[0];
            else{
            while (t != 0) {
                int a = t % 10;
                n = map[a]*place + n;
                place *= 10;
                t /= 10;
            }
            }
            newi.push_back({n, i});
        }
        sort(newi.begin(), newi.end(),[&](pair<int,int> x , pair<int,int> y){
            return x.first<y.first;
        });
        int k = 0;
        for (auto& i : nums)
            i = newi[k++].second;
        return nums;
    }
};
