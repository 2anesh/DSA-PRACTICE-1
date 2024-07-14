class Solution {
public:
    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }    
    unordered_map<string, int> dfs(int &pos, string &formula) {
        int n = formula.size();
        if (pos >= n) {
            return {};
        }
        unordered_map<string, int> curMap;
        string prev = "";
        while (pos < n) {
            if (formula[pos] == '(') {
                if (prev.size() > 0) {
                    curMap[prev] += 1;
                    prev = "";
                }
                ++pos;
                unordered_map<string, int> retMap = dfs(pos, formula);
                for (pair<string, int> entry: retMap) {
                    curMap[entry.first] += entry.second;   
                }
            } else if (formula[pos] == ')') {
                if (prev.size() > 0) {
                    curMap[prev] += 1;
                    prev = "";
                }
                int val = 0;
                if (pos + 1 < n) {
                    ++pos;
                    while (pos < n) {
                        if (isDigit(formula[pos])) {
                            val = val * 10 + formula[pos] - '0';
                        } else break;
                        ++pos;
                    }
                }
                val = val > 0? val : 1;
                for (auto &entry: curMap) {
                    entry.second *= val;
                }
                return curMap;
            } else {
                if (isDigit(formula[pos])) {
                    int val = 0;
                    while (pos < n) {
                        if (isDigit(formula[pos]))
                            val = val * 10 + formula[pos] - '0';
                        else break;
                        ++pos;
                    }
                    if (prev.size() > 0) {
                        curMap[prev] += val;
                        prev = "";
                    }                
                } else {
                    if (prev.size() > 0 && isupper(formula[pos])) {
                        curMap[prev] += 1;
                        prev = "";
                    }
                    prev += formula[pos];
                    ++pos;
                }
            }
        }
        if (prev.size() > 0) {
            curMap[prev] += 1;
        }
        return curMap;
    }
    
    string countOfAtoms(string formula) {
        int pos = 0;
        unordered_map<string, int> f = dfs(pos, formula);
        vector<string> res;
        for (pair<string, int> entry: f) {
            res.push_back(entry.first);
        }
        sort(begin(res), end(res), [&] (const string &a, const string &b) {
            return a < b;
        });
        string result = "";
        for (string s: res) {
            result += s;
            if (f[s] > 1)
                result += to_string(f[s]);
        }
        return result;
    }
};
