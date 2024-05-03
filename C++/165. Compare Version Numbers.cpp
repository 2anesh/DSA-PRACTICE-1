class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, ans1=0, ans2=0;
        while(i<version1.size() || j<version2.size()){
            while(i<version1.size() && version1[i]!='.'){
                ans1*=10;
                ans1+=(version1[i]-'0');
                i++;
            }
            while(j<version2.size() && version2[j]!='.'){
                ans2*=10;
                ans2+=(version2[j]-'0');
                j++;
            }
            if(ans1<ans2){return -1;}
            if(ans1>ans2){return 1;}
            i++;
            j++;
            ans1=0;
            ans2=0;
        }
        return 0;
    }
};
