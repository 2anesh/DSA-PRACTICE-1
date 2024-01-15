class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2, vector<int>());
        map<int, int> win, lose; 
        for(int i=0;i<matches.size();i++){
            int w=matches[i][0];
            int l=matches[i][1];
            win[w]++;  
            lose[l]++;  
        }
        for(auto it: win){
            if((it.second)>0 and lose.find(it.first)==lose.end()){  
                res[0].push_back(it.first);
            }
        }
        for(auto it: lose){
            if(it.second==1){
                res[1].push_back(it.first);
            }
        }
        return res;
    }
};
