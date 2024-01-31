class Solution {
    public int[] dailyTemperatures(int[] temp)
    {
        Stack <Integer> list =new Stack<>();
        int l=temp.length;
        int ans[]=new int[l];
        int ind=l-1;
        int top=0;
        list.push(l-1);
        ans[ind]=0;
        ind--;
        for(int i=l-2;i>=0;i--)
        {
            if(temp[i]<temp[list.get(top)])
            {
                ans[ind]=list.get(top)-i;
                ind--;
                list.push(i);
                top+=1;
            }
            else
            {
                while (top>=0 && temp[i]>=temp[list.get(top)])
                {
                    top-=1;
                    list.pop();
                }
                if(top<0)
                    ans[ind]=0;
                else
                    ans[ind]=list.get(top)-i;
                ind--;
                list.push(i);
                top+=1;
            }
        }
        
        return ans;
        
    }
}
