class Solution {
public:
string fractionAddition(string expression) {
    if(expression.empty()) return "";
    int n = expression.size();
    int a = 0, b = 1, sign = 1;
    int i = 0;
    while(i < n){
        int sign_tmp = 1;
        if(expression[i] == '+' || expression[i] == '-'){
            sign_tmp = expression[i] == '+' ? 1 : -1;
            i++;
        }
        int a_tmp = 0;
        int b_tmp = 0;
        while(i < n && isdigit(expression[i])){
            a_tmp = a_tmp * 10 + expression[i] - '0';
            i++;
        }
        if(i < n && expression[i] =='/') i++;
        while(i < n && isdigit(expression[i])){
            b_tmp = b_tmp * 10 +  expression[i] - '0';
            i++;
        }
        a = sign * a * b_tmp + sign_tmp * b * a_tmp;
        b = b * b_tmp;
        sign = a < 0 ? -1 : 1;
        a = sign * a;
        simplify(a, b);
    }
    string res = sign == -1 ? "-" : "";
    res += to_string(a) + "/" + to_string(b);
    return res;
}
void simplify(int& a, int& b){
    int tmp1 = a, tmp2 = b;
    while(tmp2 > 0){
        int r = tmp2;
        tmp2 = tmp1 % tmp2;
        tmp1 = r;
    }
    a = a/tmp1;
    b = b/tmp1;
}
};
