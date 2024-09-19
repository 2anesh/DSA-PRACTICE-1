class Solution {
    public List<Integer> diffWaysToCompute(String exp) {
        List<Integer> ans  = new ArrayList<>();
        for(int i=0;i<exp.length();i++)
        {
            char ch = exp.charAt(i);
            if(ch=='+'||ch=='-'||ch=='*')
            {
                String a = exp.substring(0,i);
                String b = exp.substring(i+1);
                List<Integer> a1 = diffWaysToCompute(a);
                List<Integer> b1 = diffWaysToCompute(b);
                for(int x:a1)
                {
                    for(int y:b1)
                    {
                        if(ch=='+')
                        ans.add(x+y);
                        else if(ch=='-')
                        ans.add(x-y);
                        else if(ch=='*')
                        ans.add(x*y);
                    }
                }
            }
        }
        if(ans.size()==0)
        ans.add(Integer.valueOf(exp));
        return ans;
    }
}
