class Solution {
  public:
   vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i=0, j=0;
        int p_i=0, p_j=0;
        char ch = 'R';
        while(i>=0 and j>=0 and i<n and j<m){
            p_i = i;
            p_j = j;
            if(matrix[i][j]==0){
                if(ch=='R') j++;
                else if(ch=='D') i++;
                else if(ch=='L') j--;
                else i--;
            }
            else{
                matrix[i][j] = 0;
                if(ch=='R'){
                    ch='D';
                    i++;
                }
                else if(ch=='D'){
                    ch='L';
                    j--;
                }
                else if(ch=='L'){
                    ch='U';
                    i--;
                }
                else{
                    ch='R';
                    j++;
                }
            }
        }
        
        return {p_i, p_j};
    }
};
