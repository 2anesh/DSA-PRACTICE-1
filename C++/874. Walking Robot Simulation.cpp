class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans=0;
        int x=0,y=0;
        int a=0,b=0;
        int idx=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        set<pair<int,int>> s;
        for(auto x:obstacles){
            s.insert(make_pair(x[0],x[1]));
        }
        for(auto c:commands){
            if(c==-2){
                idx=(idx+3)%4;
            }else if(c==-1){
                 idx=(idx+1)%4;
            }else{
                 a=x;
                 b=y;
                for(int i=1;i<=c;i++){
                    a+=dx[idx];
                    b+=dy[idx];
                    auto p=make_pair(a,b);
                    if(s.count(p)!=0){
                        break;
                    }else{
                        x=a,y=b;
                    }
                }
                ans=max(ans,(x*x+y*y));
            }
        }
        return ans;
    }
};
