class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;
		for (auto const& element : arr)
		{
			um[element]++;
		}
		int pos = 0;
		for (auto const& element : arr)
		{
			if (um[element] == 1) {
				pos++;
			}
			if (pos == k)
			{
				return element;
			}
		}
		return "";
    }
};
