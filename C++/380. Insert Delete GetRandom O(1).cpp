class RandomizedSet {
    private:
        vector<int> nums; 
        unordered_map<int,int> x; 
    public:
        RandomizedSet() {
        }
        bool insert(int value) {
            if (x.find(value) != x.end()) {return false;}
            nums.emplace_back(value);
            x[value] = nums.size() -1;
            return true;
        }
        bool remove(int value) {
            if (x.find(value) == x.end()){return false;}
            int last = nums.back();
            x[last] = x[value]; 
            nums[x[value]] = last; 
            nums.pop_back();
            x.erase(value);
            return true;
        }
        int getRandom() {
            return nums[rand() % nums.size()];
        }
};
