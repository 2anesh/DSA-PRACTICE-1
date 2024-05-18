class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int n=rating.size(),i,j,count;
        int left[n],right[n];
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<i;j++)
            {
                if(rating[i]>rating[j])
                {
                    count++;
                }
            }
            left[i]=count;
        }
        for(i=n-1;i>=0;i--)
        {
            count=0;
            for(j=n-1;j>i;j--)
            {
                if(rating[i]>rating[j])
                {
                    count++;
                }
            }
            right[i]=count;
        }
        int res=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(rating[i]>rating[j])
                {
                    res+=left[j];
                }
            }
        }
        for(i=n-1;i>=0;i--)
        {
            for(j=n-1;j>i;j--)
            {
                if(rating[i]>rating[j])
                {
                    res+=right[j];
                }
            }
        }
        return res;
    }
};
