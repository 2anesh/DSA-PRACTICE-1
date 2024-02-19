class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int> mp;
        int n = s.size();
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for(it:mp){
            pq.push(it.second);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp--;
            pq.push(temp);
        }
        int ans = 0;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};
