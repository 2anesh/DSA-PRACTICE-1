class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int currentUnsatifiedCustomer=0;
        for(int i=0;i<minutes;i++){
            currentUnsatifiedCustomer+=customers[i]*grumpy[i];
        }
        int maximumUnsatifiedCustomer=currentUnsatifiedCustomer;
        int i=0;
        int j=minutes;
        while(j<n){
            currentUnsatifiedCustomer+=customers[j]*grumpy[j];
            currentUnsatifiedCustomer-=customers[i]*grumpy[i];            maximumUnsatifiedCustomer=max(maximumUnsatifiedCustomer,currentUnsatifiedCustomer);
            i++;
            j++;
        }
        int totalUnsatisfiedCust=maximumUnsatifiedCustomer;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                totalUnsatisfiedCust+=customers[i];
            }
        }
        return totalUnsatisfiedCust;
    }
};
