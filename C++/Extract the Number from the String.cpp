class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long int result = 0;
        bool flag = 0;
        bool has9 = 0;
        long long int temp = 0;
        for(char i:sentence){
            if (i>=48 && i<=57 && !flag)
            {
                flag = 1;
                has9 = 0;
                temp = 0;
            }
            else if(i<48 || i>57 && flag){
                flag = 0;
                if(!has9 && temp > result) result = temp;
            }
            if(flag) {
                if (i == 57) has9 = 1;
                temp = temp*10 + i%48;
            }
        }
        if (!has9 && temp > result) result = temp;
        return (result == 0)? -1 : result;
    }
};
