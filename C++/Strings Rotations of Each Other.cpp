class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1 == s2)
          return true;
        string tmp = s1 + s1;
        if (tmp.find(s2) != std::string::npos)
           return true;
        return false;   
    }
};
