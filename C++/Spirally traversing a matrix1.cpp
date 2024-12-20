class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
       int n = mat.size();
       int m = mat[0].size();
       int i = 0,j = 0;
       int sti = 0,stj = 0;
       vector<int>ans;
       if(n ==  1|| m == 1)
       {
           for(int p = 0;p<n;p++)
           {
               for(int q = 0; q <m;q++)
               {
                   ans.push_back(mat[p][q]);
               }
           }
           return ans;
       }
       int inci = 0,incj = 1;
       for(int l = 0 ;l < mat.size()*mat[0].size();l++)
       {
           ans.push_back(mat[i][j]);
           i += inci;
           j += incj;
           if(j == m)
           {
               incj = 0;
               inci = 1;
               sti++;
               i = sti;
               j = m-1;
               
           }
           else if(i == n)
           {
               incj = -1;
               inci = 0;
               m--;
               j = m-1;
               i = n-1;
              
               
           }
           else if(j == stj - 1)
           {
               j = stj;
               n--;
               i = n-1;
               incj = 0;
               inci = -1;
               
           }
           else if(i == sti-1)
           {
               i = sti;
               stj++;
               j = stj;
               incj = 1;
               inci = 0;
           }
       }
       return ans;
    }


};
