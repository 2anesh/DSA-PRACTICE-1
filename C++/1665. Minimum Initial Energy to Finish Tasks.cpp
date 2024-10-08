class Solution {
public:    
    static bool cmp(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b)
    {
        if(a.first==b.first)
        {
            return a.second.second>b.second.second;
        }
        else
            return a.first>b.first;            
    }    
    int minimumEffort(vector<vector<int>>& tasks) 
    {        
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<tasks.size();i++)
            v.push_back({tasks[i][1]-tasks[i][0],{tasks[i][0],tasks[i][1]}});        
        sort(v.begin(),v.end(),cmp);        
        int sum=0;
        int n=tasks.size();        
        for(int i=0;i<n;i++)
            sum+=v[i].second.first;        
        sum=max(sum,v[0].second.second);        
        int temp=sum;        
        for(int i=0;i<v.size();i++)
        {
            if(temp>=v[i].second.second)
            {
                temp=temp-v[i].second.first;
            }
            else
            {
                sum+=abs(temp-v[i].second.second);
                temp+=abs(temp-v[i].second.second);
                temp=temp-v[i].second.first;
            }
        }       
        return sum;        
    }
};
