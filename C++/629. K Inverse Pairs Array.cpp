class Solution {
public:
int kInversePairs(int n, int k) {
int mod = 1e9+7;
    vector<int> p(k+1);    
    p[0] = 1;    
    vector<int> q(k+1);    
    for(int i=2;i<=n;i++){
        int add = 0;
        for(int j=0;j<=k;j++){
            add += p[j];            
            if(j-i >=0)
                add -= p[j-i];            
            if(add < 0){
                add += mod;
            }            
            else
                add %= mod;
            
            q[j] = add;
        }        
        p = q;
    }    
    return p[k];
}
};
