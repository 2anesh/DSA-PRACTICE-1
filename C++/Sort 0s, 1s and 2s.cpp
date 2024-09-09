class Solution {
  public:
    void sort012(vector<int>& arr) {
        int ones = 0, zeros = 0, twos = 0;
        int i = 0;
        for(auto it: arr){
            if(it==0){
                zeros++;
            }
            else if(it == 1){
                ones++;
            }
            else{
                twos++;
            }
            arr[i] = 2;
            i++;
        }
        i = 0;
        while(zeros--){
            arr[i] = 0;
            i++;
        }
        while(ones--){
            arr[i] = 1;
            i++;
        }
    }
};
