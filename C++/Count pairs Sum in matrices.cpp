class Solution{
public:	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int ans=0;
	    int l=0,r=n*n-1;
	    while(l<n*n and r>=0){
	        if(mat1[l/n][l%n]+mat2[r/n][r%n]==x){
	            ans++;
	            l++;r--;
	        }
	        else if(mat1[l/n][l%n]+mat2[r/n][r%n]>x)r--;
	        else l++;
	    }
	    return ans;
	}
};
