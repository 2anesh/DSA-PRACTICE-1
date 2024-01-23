class Solution {
public:
    int maxLength(vector<string>& arr) {
        this->arr = arr;
        this->str_as_bits = vector<unsigned>(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                unsigned to_add = 1 << (arr[i][j] - 'a');
                if ((to_add & str_as_bits[i]) != 0) {
                    str_as_bits[i] = 0;
                    break;
                }
                str_as_bits[i] += to_add;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (str_as_bits[i] == 0) continue;
            attemp(0, 0, i);
        }        
        return this->max_length;        
    }    
private:
    vector<unsigned> str_as_bits;
    vector<string> arr;
    int max_length = 0;    
    void attemp(unsigned cur, int curLength, int i) {
        if (i >= arr.size()) return;
        if (cur > 0) {
            attemp(cur, curLength, i+1);
        }
        if (str_as_bits[i] != 0 && (cur & str_as_bits[i]) == 0) {
            cur += str_as_bits[i];
            curLength += arr[i].size();
            max_length = max(max_length, curLength);
            attemp(cur, curLength, i+1);
        }
    }
};
