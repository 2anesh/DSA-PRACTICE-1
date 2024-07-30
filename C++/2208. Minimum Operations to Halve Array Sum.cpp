class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<long double> pq;     
        long double tot=0;
        for(auto it:nums) tot+=it;
        long double half=tot/2;    
        for(auto it:nums) pq.push(it);        
        int cnt=0;        
        while(!pq.empty()){        
            long double a=pq.top()/2;
            pq.pop();           
            tot-=a;
            cnt++;
            if(tot<=half) break;          
            pq.push(a);          
        }
        return cnt;
    }
};
