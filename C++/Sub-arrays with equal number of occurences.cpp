class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        map<int,int> mp;
        int fx=0, fy=0, ans=0, sum=0;
        mp[0]=1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==x){
                fx++;
            }
            if(arr[i]==y){
                fy++;
            }
            sum = fx-fy;
            if(mp.find(sum)!=mp.end()){
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};
