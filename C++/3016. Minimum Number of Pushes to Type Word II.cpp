class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>m;
        for(auto it : word)
        {
            m[it]++;
        }
        vector<int>v;
        for(auto it : m)
        {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end(),greater<>());
        int place = 8;
        int press = 1;
        int ans = 0;
        for(auto it : v){
            if(place == 0)
            {
                press++;
                place = 8;
            }
            ans += it*press;
            place--;
        }
        return ans;        
    }
};
