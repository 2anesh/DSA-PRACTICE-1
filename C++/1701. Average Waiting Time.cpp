class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int>v(customers.size(),0);
        if(customers.size()==1){
            return customers[0][1];
        }
        long long int ans=customers[0][0]+customers[0][1];
        v[0]=customers[0][1];
        long long int total=v[0];
        for(int i=1;i<customers.size();i++){
              long long int ans1;
            if(ans>customers[i][0])
            ans1=ans+customers[i][1];
            else
                ans1=customers[i][0]+customers[i][1];
            ans=ans1;
            if(ans1<customers[i][0]){
                v[i]=customers[i][1];
            }
            else
            v[i]=ans1-customers[i][0];
            total+=v[i];
        }
        return total*(1.0)/customers.size();
    }
};
