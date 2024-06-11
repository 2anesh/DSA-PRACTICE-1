class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>hashmap {};
        vector<int>result;
        vector<int>notpresent;
        for(int i = 0; i < arr1.size(); i++){
            hashmap[arr1[i]] += 1;
        }
        for(int j = 0; j < arr2.size(); j++){
            for(int k = 0; k < hashmap[arr2[j]]; k++){
                result.push_back(arr2[j]);
            }
        }
        for(int i = 0; i < arr1.size(); i++){
            auto it = find(arr2.begin(), arr2.end(), arr1[i]);
            bool ispresent = (it != arr2.end());
            if(!ispresent)
                notpresent.push_back(arr1[i]);
        }
        sort(notpresent.begin(),notpresent.end());
        result.insert(result.end(),notpresent.begin(),notpresent.end());
        return result;
    }
};
