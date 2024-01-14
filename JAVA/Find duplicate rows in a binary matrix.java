class Solution
{
    public static ArrayList<Integer> repeatedRows(int matrix[][], int m, int n)
    {
        ArrayList<Integer> ans= new ArrayList<>();
        HashSet<String> hs= new HashSet<>();
        for(int i=0;i<m;i++){
            StringBuilder sb= new StringBuilder();
            for(int j=0;j<n;j++){
                sb.append(matrix[i][j]);
            }
           
            if(hs.contains(sb.toString()))ans.add(i);
            else hs.add(sb.toString());
        }
        return ans;
    }
}
