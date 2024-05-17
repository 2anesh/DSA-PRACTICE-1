class Solution {
public:
    bool match(string temp,string pre){
        int cnt=0;
        for(int i=0;i<10;i++){
            if(pre[i]=='1' && temp[i]=='0'){
                cnt++;
            }
        }
        return cnt==4;
    }    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for(auto it:reservedSeats){
            mp[it[0]].push_back(it[1]);
        }        
        int count=0;
        for(auto it:mp){
            string temp="0000000000";
            for(auto it1:it.second){
                temp[it1-1]='1';
            }            
            bool p1=match(temp,"0111100000");
            bool p2=match(temp,"0001111000");
            bool p3=match(temp,"0000011110");
            if(p1 && p3){
                count+=2;
            }else if(p1 || p2 || p3){
                count++;
            }
        }        
        return count+2*(n-mp.size());
    }
};
