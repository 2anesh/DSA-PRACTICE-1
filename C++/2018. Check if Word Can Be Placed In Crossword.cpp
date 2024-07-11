class Solution {
public:    
    bool satisfy(string &s, string &word)
    {
        if(s.length() == 0)
        {
            return false;
        }
        else if((int)s.length() != (int)word.length())
        {
            return false;
        }
        else
        {
            string rev = s;
            reverse(rev.begin(), rev.end());            
            bool ans = true;            
            int n = s.length();
            for(int i = 0 ; i < n ; ++i)
            {
                if(s[i] == ' ')
                {
                    s[i] = word[i];
                }
                else
                {
                    if(s[i] != word[i])
                        ans = false;
                }
            }            
            if(ans)
                return ans;           
            ans = true;          
            for(int i = 0 ; i < n ; ++i)
            {
                if(rev[i] == ' ')
                {
                    rev[i] = word[i];
                }
                else
                {
                    if(rev[i] != word[i])
                        ans = false;
                }
            }
            
            return ans;
        }
    }    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {        
        int n = board.size();
        int m = board[0].size();        
        for(int i = 0 ; i < n ; ++i)
        {
            string s = "";        
            for(int j = 0 ; j < m ; ++j)
            {
                if(board[i][j] == '#')
                {
                    if(satisfy(s, word))
                        return true;
                    s = "";
                }
                else if(board[i][j] == ' ')
                {
                    s += board[i][j];
                }
                else
                {
                    s += board[i][j];
                }
            }
            if(satisfy(s, word))
                return true;
        }        
        for(int j = 0 ; j < m ; ++j)
        {
            string s = "";            
            for(int i = 0 ; i < n ; ++i)
            {
                if(board[i][j] == '#')
                {
                    if(satisfy(s, word))
                        return true;
                    s = "";
                }
                else if(board[i][j] == ' ')
                {
                    s += board[i][j];
                }
                else
                {
                    s += board[i][j];
                }
            }
            if(satisfy(s, word))
                return true;
        }        
        return false;
    }
};
