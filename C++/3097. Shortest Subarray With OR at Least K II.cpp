class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        int l=0,r=0;
        int n= nums.size();
        int ans=n+1;
        vector<int> op(32,0);
        while(r<nums.size())
        {
                int x = nums[r];
                int y=0;
                while(x)
                {
                    if(x&1)
                    op[y]++;
                    y++;
                    x=x>>1;
                }
                bool xx = true;
                int pp=0;
                for(int i=0;i<=31;i++)
                {
                    if(op[i])
                    pp+=1<<i;
                }
                if(pp<k)
                xx=false;
                while(xx && l<=r)
                {
                        cout<<l<<" "<<r<<endl;
                        ans=min(r-l+1,ans);
                        int p = nums[l];
                        int q = 0;
                        int gg=0;
                        while(p)
                        {
                            if(p&1)
                            op[q]--;
                            q++;
                            p=p>>1;
                        }
                        for(int i=0;i<=31;i++)
                            {
                                if(op[i])
                                gg+=1<<i;
                            }
                        if(gg<k)
                        xx=false;
                        l++;
                }
                r++;
                
        }
        if(ans==n+1)
        return -1;
        return ans;
        
    }
};
