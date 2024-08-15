class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0,tens = 0,twens = 0;
        int indx = 0;
        for(auto ele:bills)
        {            
            if(ele == 5)fives += 1;
            else if(ele == 10)
            {
                tens += 1;
                if(fives>=1)fives -= 1;
                else return false;                
            }
            else if(ele == 20)
            {
                twens += 1;
                if(fives>=1 && tens>=1)fives -= 1,tens -= 1;
                else if(fives>=3 && tens == 0)fives -= 3;
                else return false;  
            }
        }
        return true;      
    }
};
