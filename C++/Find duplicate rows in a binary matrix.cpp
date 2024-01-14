class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>>st;
        vector<int>answer;
        for(int i=0;i<M;i++)
        {
            int ele=st.size();
            st.insert(matrix[i]);
            if(st.size()==ele) answer.push_back(i);
        }
        return answer;
    } 
};
