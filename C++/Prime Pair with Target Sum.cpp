class Solution {
  public:
    void f(int n,vector<int> &listofprimes)
    {
        vector<bool>prime(n+1,true);
        for(int i=2;i<=n;i++)
        {
            if(prime[i]){
                 for(int j=2*i;j<=n;j+=i){
                       prime[j]=false;
                 }
            }
        }
        for(int i=2;i<=n;i++){
            if(prime[i])
             listofprimes.push_back(i);
        }
    }
    vector<int> getPrimes(int n) {
         vector<int>listofprimes;
         f(n,listofprimes);
         int i=0,j=listofprimes.size()-1;
         while(i<=j)
         {
             if(listofprimes[i]+listofprimes[j]==n)
              return {listofprimes[i],listofprimes[j]};
              else if(listofprimes[i]+listofprimes[j]>n)
               j--;
              else
               i++;
         }
         return {-1,-1};
    }
};
