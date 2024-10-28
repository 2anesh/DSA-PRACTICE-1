class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<double>st;
        const int num=(1e5);
        for(auto x:nums){
            st.insert(x);
        }
        vector<int>temp;
        for(auto x:st){
            temp.push_back(x);
        }
        int ans=0;
        for(auto x:st){
            double val=x;
            val=sqrt(val);
            int c=0;
            while(st.find(val)!=st.end()){
                val=sqrt(val);
                c++;
            }
            ans=max(ans,c);
        }
        return ans==0?-1:ans+1;
        
    }
};
