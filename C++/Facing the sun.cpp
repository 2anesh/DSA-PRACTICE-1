class Solution {
  public:
    int countBuildings(vector<int> &height) {
        int count=0;
        int maxheight=0;
        int n=height.size();
        for(int i=0; i<n;i++)
        {
            if(height[i] > maxheight)
            {
                maxheight=height[i];
                count ++;
            }
        }
        return count;
    }
};
