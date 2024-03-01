class Solution {
public:
string maximumOddBinaryNumber(string s) {
sort(s.rbegin(),s.rend());
int n=s.size();
for(int i=n-1;i>=0;i--)
{
if(s[i]=='1')
{
int temp=s[i];
s[i]=s[n-1];
s[n-1]=temp;
}
   }
    return s;
}
};
