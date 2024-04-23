class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) 
    {
        int length=A.size();
        vector<int>ans;
        int i,j;
        for(i=1;i<=length;i++)
        {
            if(i==A[length-i])
                continue;
            
            for(j=0;j<length;j++)
            {
                if(A[j]==i)
                    break;
            }
            reverse(A.begin(),A.begin()+j+1);
            ans.push_back(j+1);
            reverse(A.begin(),A.begin()+length-i+1);
            ans.push_back(length-i+1);
        }
        ans.push_back(length);
        return ans;
        
    }
};
