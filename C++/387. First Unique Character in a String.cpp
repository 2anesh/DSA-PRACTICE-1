class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int arr[26]={0};
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            arr[ch-'a']++;
        }
        for(int j=0;j<n;j++)
        {
            if(arr[s[j]-'a']==1)
            {
                return j;
            }
        }       
        return -1;
    }
};
