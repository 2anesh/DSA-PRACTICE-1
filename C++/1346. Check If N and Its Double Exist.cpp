class Solution {
public:

bool checkIfExist(vector<int>& arr) {
    map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = i;
    }
	
    for(int i = 0; i < arr.size(); i++) {
        int k = 2 * arr[i];
        if(mp.find(k) != mp.end()) {
            if(mp.find(k)->second != i) return true;
        }
    }
    return false;
}
};
