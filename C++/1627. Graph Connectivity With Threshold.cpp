class Solution {
public:
int _gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int findp(vector<int>& find,int val){
    if(find[val] == val){
        return val;
    }
    find[val] = findp(find,find[val]);
    return find[val];
} 
vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
    vector<int> findP(n + 1);
    for(int i = 1;i <= n;i++){
        findP[i] = i;
    }
    for(int i = 1 ;i <= n;i++){
        for(int j = 1;j * j <= i;j++){
            if(i % j == 0){
                int a = i/j;
                int b = j;
                if(_gcd(i,a) > threshold){
                    findP[findp(findP,a)] = findp(findP,i);
                    findP[findp(findP,i)] = findp(findP,a);
                }
                if(_gcd(i,b) > threshold){
                    findP[findp(findP,b)] = findp(findP,i);
                    findP[findp(findP,i)] = findp(findP,b);
                }
                if(_gcd(a,b) > threshold){
                    findP[findp(findP,a)] = findp(findP,b);
                    findP[findp(findP,b)] = findp(findP,a);
                }
            }

        }
    }
    map<int,int> m;
    for(int i = 1 ; i <= n;i++){
        m[findp(findP,i)]++;
    }
    vector<bool> ans;
    for(auto it : queries){
        if(findp(findP,it[0])==findp(findP,it[1])){
            ans.push_back(true);
        }
        else{
            ans.push_back(false);
        }
    }    
    return ans;
}
};
