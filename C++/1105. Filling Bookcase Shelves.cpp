class Solution {
public:
    int dp[1001][1001] = {};
    int solve(vector<vector<int>>& books, int shelfWidth, int index, int width, int height){
        if(index >= books.size()){
            return height;
        }
        if(dp[index][width] == 0){
            dp[index][width] = height+ solve(books, shelfWidth, index + 1, books[index][0], books[index][1]);
            if(width + books[index][0] <= shelfWidth){
                dp[index][width] = min(dp[index][width], solve(books, shelfWidth, index + 1, width + books[index][0], max(height, books[index][1])));
            }
        }
        return dp[index][width];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int ans = solve(books, shelfWidth, 0, 0, 0);
        return ans;
    }
};
