class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; // max heap 
        
        for (int i = 1; i < heights.size(); ++i) {
            int diff = heights[i] - heights[i-1]; 
            if (diff > 0) {
                pq.push(diff); 
                bricks -= diff; 
                if (bricks < 0) {
                    if (ladders) {
                        bricks += pq.top(); 
                        pq.pop(); 
                        ladders -= 1; 
                    } else return i-1; 
                }
            }
        }
        return heights.size() - 1; 
    }
};
