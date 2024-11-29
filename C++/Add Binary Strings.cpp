class Solution {
  public:
    int firstOne(const string &s) {
        int index = 0;
        int len = s.size();
        while(index < len && s[index] != '1') index = index + 1;
        return index;
    }
    string addBinary(string& s1, string& s2) {
        string res = "";
        int i1 = s1.size() - 1 , i2 = s2.size() - 1;
        int carry = 0;
        int p1 = firstOne(s1) , p2 = firstOne(s2);
        int val1 , val2 , sum;
        while(i1 >= p1 || i2 >= p2) 
        {
            val1 = s1[i1] - '0' ? i1 >= p1 : 0; 
            val2 = s2[i2] - '0' ? i2 >= p2 : 0;
            sum = val1 + val2 + carry;
            carry = 1 ? sum > 1 : 0; 
            res = res + (char)(sum % 2 + '0'); 
            if(i1 >= p1) i1 = i1 - 1;
            if(i2 >= p2) i2 = i2 - 1; 
        }
        if(carry == 1)  res = res + '1';
        reverse(begin(res) , end(res));
        return res;
    }
};
