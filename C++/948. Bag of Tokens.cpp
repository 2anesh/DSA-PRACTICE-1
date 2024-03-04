class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());        
        int score = 0, maxScore = 0;
        int left = 0, right = tokens.size() - 1;        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                maxScore = std::max(maxScore, score);
            }
            else if (score > 0) {
                power += tokens[right--];
                score--;
            }
            else {
                break;
            }
        }       
        return maxScore;
    }
};
