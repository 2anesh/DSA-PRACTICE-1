class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        short target_size = target.size(), arr_size = arr.size();
        if (target_size != arr_size)
            return false;
        short c[1001] = { 0 };
        for (short i = 0; i < target_size; ++i)
            ++c[target[i]];
        for (short i = 0; i < target_size; ++i)
            --c[arr[i]];
        for (short i = 1; i < 1001; ++i)
            if (c[i] != 0)
                return false;
        return true;
    }
};
