class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        vector<int>v(10,0);
        for(int i=0;i<s.size();i++) v[s[i]-'0']=i; 
        for(int i=0;i<s.size();i++)
        {
            for(int j=9;j>s[i]-'0';j--)
            {
                if(v[j]>i)
                {
                    swap(s[i],s[v[j]]);
                    return stoi(s);
                }
            }            
        }
        return num;
    }    
};
