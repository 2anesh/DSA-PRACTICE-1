class Solution {
    int j=0;
public:
    string reversePrefix(string word, char ch) {
        for(int  i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                j=i;
                break;
            }
        }
        cout<< j;
        reverse(word.begin(),word.begin()+j+1);
        return word;
    }
};
