class Solution {
public:
    bool isPerfect(int num) {
        int x = sqrt(num);
        if (x * x == num) {
            return true;
        }
        else {
            return false;
        }
    }
    bool findElementInVector(const vector<int>& nums, int element) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element) {
                return true;
            }
        }
        return false;
    }
    vector<int> makeVectorWithout(const vector<int>& nums, int index) {
        vector<int> temp;
        for (int i = 0, j = 0; i < nums.size() -1; i++,j++) {
            if (j == index) {
                j++;
            }
            temp.push_back(nums[j]);
        }
        return temp;
    }
    int numSquarefulPerms(vector<int>& nums) {
        return squarefulNums(nums);
    }
    int squarefulNums(vector<int> nums, int prevNum = 0, bool first = true) {  
        int count = 0;
        if (nums.size() == 1) {
            if (isPerfect(nums[0] + prevNum)) { 
                return 1;
            }
            else {
                return 0;
            }
        }
        vector<int> list;
        for (int i = 0; i < nums.size(); i++) {
           if (findElementInVector(list,nums[i])) {
                continue;
            }
            list.push_back(nums[i]);
            if (isPerfect(nums[i] + prevNum) || first) {             
               vector<int> temp = makeVectorWithout(nums, i);
                count += squarefulNums(temp,nums[i], false);                
            }
        }
        return count;
    }
};
