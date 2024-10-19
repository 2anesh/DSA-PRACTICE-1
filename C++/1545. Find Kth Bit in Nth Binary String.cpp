class Solution {
public:
string invert(string s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
    return s;
}
string rev(string s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-1-i]);
    }
    return s;
}
string bits(int n,vector<string>&s){
if(s[n].size()!=0){
    return s[n];
}
    if(n==1){
        return "0";
    }
s[n]=bits(n-1,s)+"1"+rev(invert(bits(n-1,s)));
return s[n];
}
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        vector<string>s(n+1);
        s[0]="0";
        s[1]="0";
        return bits(n,s)[k-1];
    }
};
