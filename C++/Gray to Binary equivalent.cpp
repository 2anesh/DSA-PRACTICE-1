class Solution{
    public:
    int grayToBinary(int n)
    {
        int num=0;
        while(n)
        {
            num^=n;
            n>>=1;
        }
        return num;
        
    }
};
