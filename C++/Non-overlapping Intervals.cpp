class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int count =0;
        
        int spoint = intervals[0][0];
        int epoint = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(spoint == intervals[i][0])
            {
                count++;
                continue;
            }
            else if(epoint > intervals[i][0])
            {
                if(epoint < intervals[i][1])
                {
                    count++;
                }
                else
                {
                    count++;
                    spoint =intervals[i][0];
                    epoint =intervals[i][1];
                }
            }
            else if(epoint <= intervals[i][0])
            {
                spoint = intervals[i][0];
                epoint = intervals[i][1];
            }
        }
        
        return count;
    }
};
