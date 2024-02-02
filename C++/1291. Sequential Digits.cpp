class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
      vector<int> result;

        for (int i = 1; i <= 9; ++i) {
            int current = i;
            while (current <= high && current % 10 != 0) {
                if (current >= low) {
                    result.push_back(current);
                }
                current = current * 10 + (current % 10 + 1);
            }
        }

        std::sort(result.begin(), result.end());
        return result;  
    }
};
