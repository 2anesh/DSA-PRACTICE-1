class Solution{
public:
bool sameFreq(string s)
{
    unordered_map<char,int> mp;
        int maxi=0;
        for(auto i:s){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        int ct=0;
        for(auto i:mp){
            if(i.second==maxi){
                ct++;
            }
        }
        if(ct==mp.size()){
            return 1;
        }
        
        for(auto i:mp){
            mp[i.first]--;
            set<int> st;
            ct=1;
            for(auto j:mp){
                if(j.second>0)
                    st.insert(j.second);
                if(st.size()>1){
                    ct=0;
                    break;
                }
            }
            if(ct){
                return 1;
            }
            mp[i.first]++;
        }
        return 0;
}
};
