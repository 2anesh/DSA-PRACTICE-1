class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(string log:logs){
            if(log=="../"){
                if(level!=0){
                    level--;
                }
            }
            else if(log=="./"){
                continue;
            }
            else{
                level++;
            }
        }
        return level;
    }
};
