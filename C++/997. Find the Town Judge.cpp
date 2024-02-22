class Solution {
public:
    bool checkVaild(int i, vector<vector<int>>& trust)
    {
        for(auto k: trust)
            if(k[0]==i && k[1]!= i)
                return false;
        return true;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge(n + 1, 0); 
        if(n==1)        
            return 1;
        for(auto i: trust)
            judge[i[1]]++;
        for(int i=0; i<n+1; i++)
            if(judge[i]==n-1 && checkVaild(i,trust) == true)
                return i;         
        return -1;
    }
};
