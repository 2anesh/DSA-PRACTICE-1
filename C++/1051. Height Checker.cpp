class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int> org(heights.begin(), heights.end());
        sort(org.begin(), org.end());
        int sum=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!= org[i]){
                sum++;
            }
        }
        return sum;
    }
};
