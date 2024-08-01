class Solution {
public:
    int countSeniors(vector<string>& details) {
        int SeniorCtz=0;
        for(string &detail:details){
            int onesDigit=detail[12]-'0';
            int tensDigit=detail[11]-'0';
            int age=tensDigit*10+onesDigit;
            if(age>60){
                SeniorCtz++;
            }        
        }
        return SeniorCtz;
    }
};
