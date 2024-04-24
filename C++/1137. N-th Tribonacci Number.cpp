class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        int next;
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        else{
            while(n-2){
            next = a + b + c;
            a = b;
            b = c;
            c = next;
            n--;
        }
        return next;
        }

    }
};
