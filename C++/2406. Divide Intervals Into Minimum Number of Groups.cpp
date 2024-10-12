class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(const auto& interval: intervals){
            int start = interval[0];
            int end = interval[1];
            if(!minheap.empty() && minheap.top() < start){
                minheap.pop();
            }
            minheap.push(end);
        }
        return minheap.size();
    }
};
