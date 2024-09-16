class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(auto x: timePoints){
            int hours = stoi(x.substr(0, 2));
            int min = stoi(x.substr(3, 2));
            int totalMinutes = hours * 60 + min;
            minutes.push_back(totalMinutes);
        }
        sort(minutes.begin(), minutes.end());
        int mini = INT_MAX;
        int n = minutes.size();
        for( int i=0; i< n-1; i++){
            int diff = minutes[i+1]-minutes[i];
            mini = min(mini, diff);
        }
        int lastDiff = (minutes[0] + 1440) - minutes[n-1];
        mini = min(mini, lastDiff);
        return mini;
    }
};
