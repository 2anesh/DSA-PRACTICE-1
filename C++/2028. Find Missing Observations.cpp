class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        int size=rolls.size();
        for(int i=0;i<size;i++){
            sum+=rolls[i];
        }
        int total=mean*(n+size);
        int reqsum=total-sum;
        int elem=reqsum/n;
        if(elem>6 or elem<=0){
            return {};
        }
        vector<int> arr(n,elem);
        if(reqsum%n==0){
            return arr;
        }else{
            int rem=reqsum%n;
            for(int i=0;i<n;i++){
                arr[i]++;
                if(arr[i]>6 or arr[i]<=0){
                    return {};
                }
                rem--;
                if(rem==0){
                    break;
                }
            }
        }
        return arr;
    }
};
