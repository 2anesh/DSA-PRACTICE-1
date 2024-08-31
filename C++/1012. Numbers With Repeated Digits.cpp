class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> V;
        int n2 = n;
        while(n2){
            V.emplace_back(n2%10);
            n2/=10;
        }
        int len = V.size();       
        int sum = 0;
        for(int i = 0; i < len-1; i++){
            sum += 9*A(9,i);
        }       
        vector<int> dig_visited(10,0);
        for(int i = len-1; i >= 0; i--){
            int dig = V[i];
            int count = 0;
            for(int j = 0; j < dig; j++){
                if(dig_visited[j]){continue;}
                count++;
            }
            if(i == len-1){count--;}
            sum += count*A(10-(len-i), i);
            if(dig_visited[dig]){break;}
            if(i == 0 && dig_visited[dig] == 0){sum++;}
            dig_visited[dig] = 1;
        }        
        return n - sum;
    }    
    int A(int num, int len){
        int tmp = 1;
        for(int i = 0; i < len; i++){tmp *= (num-i);}
        return tmp;
    }
};
