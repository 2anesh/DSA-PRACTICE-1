class Solution {
  public:
    double fractionToDecimal(const string &fraction) {
    size_t pos = fraction.find('/');
    if (pos == string::npos) {
        cerr << "Invalid fraction format: " << fraction << endl;
        return 0.0;
    }
    int numerator = stoi(fraction.substr(0, pos));
    int denominator = stoi(fraction.substr(pos + 1));
    return static_cast<double>(numerator) / denominator;
}
    string compareFrac(string str) {
        size_t pos = str.find(",");
        string frac1 = str.substr(0,pos);
        string frac2 = str.substr(pos+2);
        double num1=fractionToDecimal(frac1);
        double num2=fractionToDecimal(frac2);
        if(num1==num2)
        return "equal";
        else if(num1>num2)
        return frac1;
        else 
        return frac2;
    }
};
