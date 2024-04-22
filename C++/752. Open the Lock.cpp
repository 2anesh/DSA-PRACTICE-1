class Solution {
public:
    vector<string> findadj(string &top)
    {
        vector<string> temp;
        string curr = top;
        
        int i=0;
        while(i<4)
        {
            curr[i] = ((curr[i]-'0')+1)%10 + '0';
            temp.push_back(curr);
            
            curr=top;
            
            curr[i] = (curr[i]-'0'+9)%10 + '0';
            temp.push_back(curr);
            
            curr=top;
            
            i++;
        }
        return temp;
    }
    int openLock(vector<string>& deadends, string target) 
    {
        if(target == "0000")
            return 0;
        
        unordered_map<string, int> dist;
        for(int i=0;i<deadends.size();i++)
            dist[deadends[i]] = -1;
    
        if(dist.find("0000") != dist.end())
            return -1;
        
        dist["0000"] = 0;
        
        queue<string> q;
        q.push("0000");
        
        while(q.size())
        {
            string top = q.front();
            q.pop();
            
            for(auto p : findadj(top))
            {
                if(dist.find(p)==dist.end())
                {
                    dist[p] = dist[top] + 1;
                    
                    if(p == target)
                        return dist[p];
                   
                    q.push(p);
                }
            }  
        }   
        if(dist.find(target) == dist.end())
            return -1;
        return dist[target];
    }
};
