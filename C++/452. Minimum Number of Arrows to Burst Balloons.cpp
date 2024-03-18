class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();

        int result = 0;
        sort(points.begin(), points.end(), cmp);

        int high = points[0][1];

        int prev = 0, curr = 1;

        while(curr < n)
        {
            if(high >= points[curr][0])
            {
                high = min(high, points[curr][1]);
                curr++; prev++;
            }
            else
            {
                result++;
                high = points[curr][1];
                curr++; prev++;
            }
        }
        return (result+1);

    }
};
